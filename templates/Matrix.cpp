//mridul1809
#include<bits/stdc++.h>
using namespace std;

//Requires these 2 defines
#define mod 1000000007
#define ll long long 


template <typename T>
class Matrix {

public:

    vector < vector <T> > A;
    int r,c;

    //Matrix with given dimensions and random values
    Matrix(int r,int c)
    {
        this->r = r;
        this->c = c;
        A.assign(r , vector <T> (c));
    }

    //Matrix with given value and dimensions
    Matrix(int r,int c,T val)
    {

        this->r = r;
        this->c = c;
        A.assign(r , vector <T> (c , val));
    }

    //Identity matrix with given dimension
    Matrix(int n)
    {
        this->r = this->c = n;
        A.assign(n , vector <T> (n));
        for(int i=0;i<n;i++)
            A[i][i] = (T)1;
    }

    //Print the matrix
    void display()
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                cout << A[i][j] << " ";

            cout << endl;
        }
    }

    //Input called to get input
    //Put custom code
    void input()
    {
        // for(int i=0;i<r;i++)
        //     for(int j=0;j<c;j++)
        //         define inout here
    }

    //Overloaded * operator to multiply 2 matrices
    //with conformable dimensions
    Matrix operator * (Matrix &B)
    {
        
        assert(c == B.r);
        int i,j,k;
        int x = r;
        int y = c;
        int z = B.c;

        Matrix <T> C(x,z,0);

        for(i=0 ; i<x ; i++)
            for(j=0 ; j<z ; j++)
                for(k=0 ; k<y ; k++)
                    C[i][j] = (C[i][j] + ( (ll)A[i][k] * (ll)B[k][j] ) )%mod;

        return C;
    }

    //Overloaded + operator to add 2 matrices
    //with same dimensions
    Matrix operator + (Matrix &B)
    {
        assert(r == B.r);
        assert(c == B.c);

        Matrix <T> C(r,c,0);
        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                C[i][j] = (A[i][j] + B[i][j])%mod;

        return C;
    }

    //Overload unary - to get negative of a matrix
    Matrix operator - ()
    {
        Matrix <T> C(r,c,0);
        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                C[i][j] = -A[i][j];

        return C;
    }

    //Overload binary - to subtract a matrix
    //from other with same dimensions
    Matrix operator - (Matrix &B)
    {
        assert(r == B.r);
        assert(c == B.c);

        Matrix <T> C(r,c,0);
        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                C[i][j] = (A[i][j] - B[i][j])%mod;
                if(C[i][j] < 0)
                    C[i][j] += mod;
            }

        return C;
    }

    //Overload ^ operator to raise a square matrix to a power
    //Using binary matrix exponentiation
    Matrix operator ^ (ll n)
    {
        assert(r == c);

        int i,j;
        Matrix C(r);

        Matrix X(r,c,0);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                X[i][j] = A[i][j];

        while(n)
        {
            if(n&1)
                C = C * X;

            X = X * X;
            n /= 2;
        }
        return C;
    }

    //Overload to access/set elements without using dot operator
    //Example :
    // Matrix m(5,3);
    // m.A[i][j] is valid to access
    // m[i][j] is valid as well
    vector<T>& operator [](int i)
    {
        assert(i < r);
        assert(i >= 0);
        return A[i];
    }

};

//Examples : 
int main()
{
    Matrix <int> X(5,3,3);
    X.display();
    cout << endl;

    Matrix <int> Y(5,3,1);

    Matrix <int> Z = X - Y;
    Z.display();
    cout << endl;

    Z = X + Y;
    Z.display();
    cout << endl;

    Matrix <int> I(5);
    I.display();
    cout << endl;

    Matrix <int> I1 = -I;
    I1.display();
    cout << endl;


    Matrix <int> F(2,2);
    F[0][0] = 1;
    F[0][1] = 1;
    F[1][0] = 1;
    F[1][1] = 0;

    F.display();
    cout << endl;

    F = F^6;
    F.display();
    cout << endl;

}
