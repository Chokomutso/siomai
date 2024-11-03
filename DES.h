#include <bitset>
#include <string>

using namespace std;

// Define constants for permutations and S-boxes
const int P10[] = {5 , 3, 8, 9, 10, 1, 2, 4, 7, 6};
const int P8[] = {4, 5, 2, 1, 6, 7, 8, 3};
const int IP[] = {2, 3, 5, 6, 7, 1, 4, 8};
const int EP[] = {4, 3, 2, 1, 4, 2, 1, 3};
const int P4[] = {2, 3, 1, 1};
const int finalPermutation[] = {6, 1, 5, 7, 3, 2, 4, 8};
const int sBox0[4][4] = {
    {1, 0, 3, 2},
    {3, 2, 1, 0},
    {0, 2, 1, 3},
    {3, 1, 3, 2}
};
const int sBox1[4][4] = {
    {0, 1, 2, 3},
    {2, 0, 1, 3},
    {3, 0, 1, 0},
    {2, 1, 0, 3}
};
// Function to apply P10 permutation
bitset<10> applyP10(bitset<10> input) {
    bitset<10> output;
    for (int i = 0; i < 10; i++) {
        output[9 - i] = input[10 - P10[i]];
    }
    return output;
}

// Function to apply P8 permutation
bitset<8> applyP8(bitset<10> input) {
    bitset<8> output;
    for (int i = 0; i < 8; i++) {
        output[7 - i] = input[10 - P8[i]];
    }
    return output;
}

// Function to apply IP permutation
bitset<8> applyIP(bitset<8> input) {
    bitset<8> output;
    for (int i = 0; i < 8; i++) {
        output[7 - i] = input[8 - IP[i]];
    }
    return output;
}

// Function to apply EP permutation
bitset<8> applyEP(bitset<4> input) {
    bitset<8> output;
    for (int i = 0; i < 8; i++) {
        output[7 - i] = input[4 - EP[i]];
    }
    return output;
}

// Function to apply P4 permutation
bitset<4> applyP4(bitset<4> input) {
    bitset<4> output;
    for (int i = 0; i < 4; i++) {
        output[3 - i] = input[4 - P4[i]];
    }
    return output;
}

// Function to apply final permutation
bitset<8> applyFinalPermutation(bitset<8> input) {
    bitset<8> output;
    for (int i = 0; i < 8; i++) {
        output[7 - i] = input[8 - finalPermutation[i]];
    }
    return output;
}

// Generate round keys from a 10-bit key
void generateRoundKeys(bitset<10> key, bitset<8>& roundKey1, bitset<8>& roundKey2) {
    cout << "Original 10-bit Key: " << key << endl;

    // Apply P10 permutation
    bitset<10> permutedKey = applyP10(key);
    cout << "After P10: " << permutedKey << endl;

    // Split and shift
    bitset<5> left = (permutedKey >> 5).to_ulong();
    bitset<5> right = (permutedKey & bitset<10>(0x1F)).to_ulong();

    // Round 1 key
    left = (left << 1 | left >> 4) & bitset<5>(0x1F);   // Left circular shift by 1
    right = (right << 1 | right >> 4) & bitset<5>(0x1F); // Right circular shift by 1
    bitset<10> combinedKey1 = (left.to_ulong() << 5) | right.to_ulong();
    roundKey1 = applyP8(combinedKey1);
    cout << "Round 1 Key (After P8): " << roundKey1 << endl;

    // Round 2 key
    left = (left << 2 | left >> 3) & bitset<5>(0x1F);   // Left circular shift by 2
    right = (right << 2 | right >> 3) & bitset<5>(0x1F); // Right circular shift by 2
    bitset<10> combinedKey2 = (left.to_ulong() << 5) | right.to_ulong();
    roundKey2 = applyP8(combinedKey2);
    cout << "Round 2 Key (After P8): " << roundKey2 << endl;
}

// Simplified F function using EP and P4
bitset<4> fFunction(bitset<4> right, bitset<8> roundKey) {
    bitset<8> expandedRight = applyEP(right);
    cout << "After Expansion Permutation (EP): " << expandedRight << endl;

    expandedRight ^= roundKey;
    cout << "After XOR with Round Key: " << expandedRight << endl;

    int row1 = (expandedRight[7] << 1) | expandedRight[4];
    int col1 = (expandedRight[6] << 1) | expandedRight[5];
    int row2 = (expandedRight[3] << 1) | expandedRight[0];
    int col2 = (expandedRight[2] << 1) | expandedRight[1];

    bitset<2> sBoxValue1(sBox0[row1][col1]);
    bitset<2> sBoxValue2(sBox1[row2][col2]);
    cout << "S0: " << sBoxValue1 << endl;
    cout << "S1: " << sBoxValue2 << endl;

    bitset<4> sBoxOutput = (sBoxValue1.to_ulong() << 2) | sBoxValue2.to_ulong();
    cout << "S0S1: " << sBoxOutput << endl;

    bitset<4> p4Output = applyP4(sBoxOutput);
    cout << "After P4: " << p4Output << endl;

    bitset<4> XOR1 = sBoxOutput ^ p4Output;
    cout << "S0S1^P4: " << XOR1 << endl;

    return XOR1;
}

// Simplified DES encryption
bitset<8> simplifiedDES(bitset<8> plaintext, bitset<8> roundKey1, bitset<8> roundKey2) {
    cout << "Initial Plaintext: " << plaintext << endl;

    bitset<8> permutedText = applyIP(plaintext);
    cout << "After Initial Permutation (IP): " << permutedText << endl;

    bitset<4> left = (permutedText >> 4).to_ulong();
    bitset<4> right = (permutedText & bitset<8>(0x0F)).to_ulong();

    for (int round = 1; round <= 2; ++round) {
        cout << "\n========================= Round " << round << " =========================\n" << endl;

        bitset<4> fOutput = fFunction(right, (round == 1 ? roundKey1 : roundKey2));

        cout << "1st 4-bits of IP: " << left << endl;
        left ^= fOutput;
        cout << "S0S1^P4^IP(1st 4): " << left << endl;

        if (round == 1) {
            swap(left, right);
            cout << "Before Swap: Right = " << right << ", Left = " << left << endl;
            cout << "After Swap: Left = " << left << ", Right = " << right << endl;
            
            bitset<8> combinedText = (left.to_ulong() << 4) | right.to_ulong();
            cout << "Round 1 Answer: " << combinedText << endl;
        }
    }

    bitset<8> combinedText = (left.to_ulong() << 4) | right.to_ulong();
    cout << "Before Final Permutation: " << combinedText << endl;

    bitset<8> cipherText = applyFinalPermutation(combinedText);
    cout << "After Final Permutation (Cipher Text): " << cipherText << endl;

    return cipherText;
}

