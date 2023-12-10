#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int uint64;
uint64 Word[80];

// constant values
const uint64 Constants[80]
    = { 0x428a2f98d728ae22, 0x7137449123ef65cd,
        0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
        0x3956c25bf348b538, 0x59f111f1b605d019,
        0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
        0xd807aa98a3030242, 0x12835b0145706fbe,
        0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
        0x72be5d74f27b896f, 0x80deb1fe3b1696b1,
        0x9bdc06a725c71235, 0xc19bf174cf692694,
        0xe49b69c19ef14ad2, 0xefbe4786384f25e3,
        0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
        0x2de92c6f592b0275, 0x4a7484aa6ea6e483,
        0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
        0x983e5152ee66dfab, 0xa831c66d2db43210,
        0xb00327c898fb213f, 0xbf597fc7beef0ee4,
        0xc6e00bf33da88fc2, 0xd5a79147930aa725,
        0x06ca6351e003826f, 0x142929670a0e6e70,
        0x27b70a8546d22ffc, 0x2e1b21385c26c926,
        0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
        0x650a73548baf63de, 0x766a0abb3c77b2a8,
        0x81c2c92e47edaee6, 0x92722c851482353b,
        0xa2bfe8a14cf10364, 0xa81a664bbc423001,
        0xc24b8b70d0f89791, 0xc76c51a30654be30,
        0xd192e819d6ef5218, 0xd69906245565a910,
        0xf40e35855771202a, 0x106aa07032bbd1b8,
        0x19a4c116b8d2d0c8, 0x1e376c085141ab53,
        0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
        0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb,
        0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
        0x748f82ee5defb2fc, 0x78a5636f43172f60,
        0x84c87814a1f0ab72, 0x8cc702081a6439ec,
        0x90befffa23631e28, 0xa4506cebde82bde9,
        0xbef9a3f7b2c67915, 0xc67178f2e372532b,
        0xca273eceea26619c, 0xd186b8c721c0c207,
        0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
        0x06f067aa72176fba, 0x0a637dc5a2c898a6,
        0x113f9804bef90dae, 0x1b710b35131c471b,
        0x28db77f523047d84, 0x32caab7b40c72493,
        0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,
        0x4cc5d4becb3e42b6, 0x597f299cfc657e2a,
        0x5fcb6fab3ad6faec, 0x6c44198c4a475817
      };


string getHex(string bin)
{
    if (bin == "0000")
        return "0";
    if (bin == "0001")
        return "1";
    if (bin == "0010")
        return "2";
    if (bin == "0011")
        return "3";
    if (bin == "0100")
        return "4";
    if (bin == "0101")
        return "5";
    if (bin == "0110")
        return "6";
    if (bin == "0111")
        return "7";
    if (bin == "1000")
        return "8";
    if (bin == "1001")
        return "9";
    if (bin == "1010")
        return "a";
    if (bin == "1011")
        return "b";
    if (bin == "1100")
        return "c";
    if (bin == "1101")
        return "d";
    if (bin == "1110")
        return "e";
    if (bin == "1111")
        return "f";
}

string decimalToHex(uint64 n)
{
    string num=bitset<64>(n).to_string();
    string ans="";
    for(int i=0;i<64;i+=4)
    {
        ans+=getHex(num.substr(i,4));
    }
    return ans;
}

uint64 ROTR(uint64 x,int n)
{
    return (x>>n)|(x<<(64-n));
}

uint64 ch(uint64 e,uint64 f,uint64 g)
{
    return (e&f)^(~e&g);
}

uint64 maj(uint64 a,uint64 b,uint64 c)
{
    return (a&b)^(a&c)^(b&c);
}

uint64 sumA(uint64 a)
{
    return ROTR(a,28)^ROTR(a,34)^ROTR(a,39);
}

uint64 sumE(uint64 e)
{
    return ROTR(e,14)^ROTR(e,18)^ROTR(e,41);
}

uint64 sigma0(uint64 w)
{
    return ROTR(w,19)^ROTR(w,61)^(w<<6);
}

uint64 sigma1(uint64 w)
{
    return ROTR(w,1)^ROTR(w,8)^(w<<7);
}

void messageSchedule(string m)
{
    int track=0;
    for(int i=0;i<m.size();i+=64,track++)
    {
        Word[track]=bitset<64>(m.substr(i,64)).to_ullong();  // string to uint64
    }

    // after 15th word;
    uint64 w1,w2,w3,w4;
    for(int i=16;i<80;i++)
    {
        //w1= ROTR(Word[i-2],19)^ROTR(Word[i-2],61)^(Word[i-2]<<6);   // sigma function1
        w1= sigma0(Word[i-2]);
        w2= Word[i-7];
        //w3= ROTR(Word[i-15],1)^ROTR(Word[i-15],8)^(Word[i-15]<<7);   // s f 0
        w3= sigma1(Word[i-15]);
        w4= Word[i-16];

        Word[i]=w1+w2+w3+w4;
    }
}


string sha512(string s)
{
    //512-bit buffer value
    uint64 A = 0x6a09e667f3bcc908;
    uint64 B = 0xbb67ae8584caa73b;
    uint64 C = 0x3c6ef372fe94f82b;
    uint64 D = 0xa54ff53a5f1d36f1;
    uint64 E = 0x510e527fade682d1;
    uint64 F = 0x9b05688c2b3e6c1f;
    uint64 G = 0x1f83d9abfb41bd6b;
    uint64 H = 0x5be0cd19137e2179;

    uint64 AI,BI,CI,DI,EI,FI,GI,HI;

    stringstream givenString;
    for(int i=0;i<s.size();i++)
    {
        givenString<<bitset<8>(s[i]);
    }

    string originalMessage;
    originalMessage=givenString.str();
    int originalLength=originalMessage.size();
    int paddedLength;
    int modValue=originalLength%1024;

    if((1024-modValue)>128)
    {
        paddedLength=1024-modValue;
    }
    else
    {
        paddedLength=2048-modValue;
    }

    originalMessage+='1';
    for(int i=0;i<paddedLength-129;i++)
    {
        originalMessage+='0';
    }

    string Size=bitset<128>(originalLength).to_string();
    originalMessage+=Size;

    int blockNumber=originalMessage.size()/1024;
    string blocks[blockNumber];

    int track=0;
    for(int i=0;i<originalMessage.size();i+=1024,track++)
    {
        blocks[track]=originalMessage.substr(i,1024);
    }

    // process each block
    for(int i=0;i<blockNumber;i++)
    {
        messageSchedule(blocks[i]);

        AI=A,BI=B,CI=C,DI=D,EI=E,FI=F,GI=G,HI=H;

        // round function
        for(int i=0;i<80;i++)
        {
            uint64 t1=H+ch(E,F,G)+sumE(E)+Word[i]+Constants[i];
            uint64 t2=sumA(A)+maj(A,B,C);

            // update
            H=G;
            G=F;
            F=E;
            E=D+t1;
            D=C;
            C=B;
            B=A;
            A=t1+t2;
        }

        A+=AI,B+=BI,C+=CI,D+=DI,E+=EI,F+=FI,G+=GI,H+=HI;
    }

    stringstream output;
    output<<decimalToHex(A);
    output<<decimalToHex(B);
    output<<decimalToHex(C);
    output<<decimalToHex(D);
    output<<decimalToHex(E);
    output<<decimalToHex(F);
    output<<decimalToHex(G);
    output<<decimalToHex(H);

    return output.str();
}

int main()
{
    freopen("message1.txt","r",stdin);
    string s;
    getline(cin,s);
    cout<<s<<"\n";
    cout<<"Hash Value: "<<sha512(s);
}
