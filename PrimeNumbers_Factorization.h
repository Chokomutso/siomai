#include <cstring>

using namespace std;

// ================== Sieve Of Eratosthenes ==================

void SieveOfEratosthenes(int n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    int count = 0;  
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            cout << setw(7) << p;  // Format to a width of 3
            count++; 

            // Print separator
            if (count < 10) {
                cout << " | ";  // Print separator for the first 9 numbers
            }

            // After printing 10 numbers, move to the next line
            if (count == 10) {
                cout << endl;  // New line after 10 numbers
                count = 0;  // Reset the counter
            }
        }
    }

    // If there are remaining numbers to print, add a newline
    if (count != 0) {
        cout << endl;  // Ensure a new line if there are remaining numbers
    }
}

// ================== Prime Factorization ==================

void primeFactors(int n) 
{ 
    bool first = true;

    while (n % 2 == 0) 
    { 
        if (!first) 
            cout << " * "; 
        cout << 2;
        n = n / 2; 
        first = false; 
    } 

    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        while (n % i == 0) 
        { 
            if (!first) 
                cout << " * "; 
            cout << i;
            n = n / i; 
            first = false; 
        } 
    } 

    if (n > 2) 
    {
        if (!first) 
            cout << " * ";
        cout << n; 
    } 
}

// ================== Euclidean Algorithm ==================
int gcd(int num1, int num2)
{
    if (num1 == 0)
        return num2;
    return gcd(num2 % num1, num1);
}

// ================== Fibonacci Sequence ==================

void printFibonacci(int n) {
    long long t1 = 0, t2 = 1, nextTerm = 0;
    int count = 0; 

    cout << "Fibonacci Series: \n";

    for (int i = 0; i <= n; ++i) {
        
        if (i == 0) {
            cout << setw(10) << t1;
            count++;
        }
        else if (i == 1) {
            cout << setw(10) << t2;
            count++;
        }
        else {
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
            cout << setw(10) << nextTerm;
            count++;
        }

       
        if (count < 5) {
            cout << " | ";  
        }

        
        if (count == 5) {
            cout << endl;  
            count = 0;     
        }
    }

    if (count != 0) {
        cout << endl;
    }
}

// ================== Egyptian Fraction ==================

void egyptianFraction(int n, int d)
{
  //When Both Numerator and denominator becomes zero then we simply return;
    if (d == 0 || n == 0)
        return;
    if (d % n == 0) {
        cout << "1/" << d / n;
        return;
    }
    if (n % d == 0) {
        cout << n / d;
        return;
    }
    if (n > d) {
        cout << n / d << " + ";
        egyptianFraction(n % d, d);
        return;
    }
    int x = d / n + 1;
    cout << "1/" << x << " + ";
    egyptianFraction(n * x - d, d * x);
}


