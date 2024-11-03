#include <vector>

// ================== Modular Arithmetic ==================
// Function to perform modular addition
int modAdd(const vector<int> &numbers, int mod) {
    int result = 0;
    for (size_t i = 0; i < numbers.size(); i++) {
        result = (result + numbers[i] % mod) % mod;
    }
    return result;
}

// Function to perform modular subtraction
int modSubtract(const vector<int> &numbers, int mod) {
    int result = numbers[0] % mod;
    for (size_t i = 1; i < numbers.size(); i++) {
        result = (result - numbers[i] % mod + mod) % mod;
    }
    return result;
}

// Function to perform modular multiplication
int modMultiply(const vector<int> &numbers, int mod) {
    int result = 1;
    for (size_t i = 0; i < numbers.size(); i++) {
        result = (result * (numbers[i] % mod)) % mod;
    }
    return result;
}

// Function to perform modular exponentiation
int modExponent(int base, int exponent, int mod) {
    int result = 1;
    base = base % mod;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        exponent = exponent >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Function to find modular inverse using Extended Euclidean Algorithm
int modInverse(int a, int mod) {
    int m0 = mod, x0 = 0, x1 = 1;
    if (mod == 1) return 0;

    while (a > 1) {
        int q = a / mod;
        int t = mod;
        mod = a % mod, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to perform modular division
int modDivide(int a, int b, int mod) {
    a = a % mod;
    int inv = modInverse(b, mod);
    if (inv == -1) {
        cout << "Division not possible";
        return -1;
    } else {
        return (inv * a) % mod;
    }
}

// ================== Caesar Cipher ==================
string encrypt(string text, int s){
    string result = "";

    // traverse text
    for (int i = 0; i < text.length(); i++) {
        // apply transformation to each character
        // Encrypt Uppercase letters
        if (isupper(text[i]))
            result += char(int(text[i] + s - 65) % 26 + 65);

        // Encrypt Lowercase letters
        else
            result += char(int(text[i] + s - 97) % 26 + 97);
    }
// Return the resulting string
    return result;
}

// =============== Diffie-Hellman Algorithm ===============
// Function to calculate the power of a^b mod P
long long int power(long long int a, long long int b, long long int P) {
    if (b == 0)
        return 1; // Adjusted to handle the case when b is 0
    long long int result = 1;
    while (b > 0) {
        if (b % 2 == 1) // If b is odd, multiply a with result
            result = (result * a) % P;
        a = (a * a) % P; // Square a
        b /= 2; // Divide b by 2
    }
    return result;
}

// Function to execute the Diffie-Hellman Key Exchange algorithm
void diffieHellmanKeyExchange(long long int P, long long int G, long long int a, long long int b) {
    cout << "\nP = " << P << endl;
    cout << "G = " << G << endl;

    long long int x = power(G, a, P); // Alice's generated key
    long long int y = power(G, b, P); // Bob's generated key
	
	cout << "Public Key for Bob = " << x << endl;
    cout << "Public Key for Alice = " << y << endl;
	
    // Generating the secret key after the exchange of keys
    long long int ka = power(y, a, P); // Secret key for Alice
    long long int kb = power(x, b, P); // Secret key for Bob

    cout << "Shared secret key for Alice is : " << ka << endl;
    cout << "Shared secret key for Bob is : " << kb << endl;
}

// =============== RSA ===============
// Function to calculate gcd
int gcd2(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// Function for modular exponentiation (base^exp % mod)
int modExp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// RSA encryption and decryption
void rsaEncryptionDecryption(int PT, int p, int q, int e) {
    // Calculating n and phi
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Ensure that e is co-prime with phi
    while (gcd2(e, phi) != 1) {
        cout << "The value of e must be co-prime with " << phi << ". Please enter a different e: ";
        cin >> e;
    }

    // Calculating the private key 'd' using a loop to find integer values
    int i = 1;
    int d;
    while (true) {
        d = ((phi*i)+1) / e;
        if (((phi*i)+1) % e == 0) {  // Check if d is an integer
            break;
        }
        i++;
    }

    cout << "\nd: " << d << endl;
    cout << "Public Key (e,n): (" << e << "," << n << ")\n";
    cout << "Private Key (d,n): (" << d << "," << n << ")\n";

    // Encryption: c = (msg ^ e) % n
    int c = modExp(PT, e, n);
    cout << "CT: " << c << endl;

    // Decryption: m = (c ^ d) % n
    int m = modExp(c, d, n);
    cout << "PT: " << m << endl;
}
