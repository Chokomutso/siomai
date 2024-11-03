#include <stdint.h>

// AES S-box for SubBytes step
const uint8_t sbox[256] = {
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};


// Function to print the state matrix
void printState(uint8_t state[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << hex << setw(2) << setfill('0') << (int)state[i][j] << " ";
        }
        cout << endl;
    }
//    cout << endl;
}

// SubBytes step
void SubBytes(uint8_t state[4][4]) {
    cout << "\nSubBytes:\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            state[i][j] = sbox[state[i][j]];
        }
    }
    printState(state);
}

// ShiftRows step
void ShiftRows(uint8_t state[4][4]) {
    cout << "\nShiftRows:\n";
    
    // Row 1: Shift left by 1
    uint8_t temp = state[1][0];
    for (int j = 0; j < 3; ++j) {
        state[1][j] = state[1][j + 1];
    }
    state[1][3] = temp;

    // Row 2: Shift left by 2
    temp = state[2][0];
    state[2][0] = state[2][2];
    state[2][2] = temp;
    temp = state[2][1];
    state[2][1] = state[2][3];
    state[2][3] = temp;

    // Row 3: Shift left by 3
    temp = state[3][3];
    for (int j = 3; j > 0; --j) {
        state[3][j] = state[3][j - 1];
    }
    state[3][0] = temp;

    printState(state);
}

// MixColumns step
uint8_t gmul(uint8_t a, uint8_t b) {
    uint8_t p = 0; // Initialize product
    while (b) {
        if (b & 1) {
            p ^= a; // Add a if the lowest bit of b is set
        }
        // Multiply a by 2 and reduce modulo 0x1b
        uint8_t highbit = a & 0x80; // Keep track of the highest bit
        a <<= 1; // Shift left by 1
        if (highbit) {
            a ^= 0x1b; // Reduce modulo
        }
        b >>= 1; // Shift b right
    }
    return p;
}

// MixColumns step
void MixColumns(uint8_t state[4][4]) {
    cout << "\nMixColumns:\n";
    uint8_t temp[4][4]; // Temporary array to store the results

    for (int j = 0; j < 4; ++j) {
        // Calculate each element in the new column based on the MixColumns matrix
        temp[0][j] = gmul(0x02, state[0][j]) ^ gmul(0x03, state[1][j]) ^ gmul(0x01, state[2][j]) ^ gmul(0x01, state[3][j]);
        temp[1][j] = gmul(0x01, state[0][j]) ^ gmul(0x02, state[1][j]) ^ gmul(0x03, state[2][j]) ^ gmul(0x01, state[3][j]);
        temp[2][j] = gmul(0x01, state[0][j]) ^ gmul(0x01, state[1][j]) ^ gmul(0x02, state[2][j]) ^ gmul(0x03, state[3][j]);
        temp[3][j] = gmul(0x03, state[0][j]) ^ gmul(0x01, state[1][j]) ^ gmul(0x01, state[2][j]) ^ gmul(0x02, state[3][j]);
    }

    // Copy the results back to the state
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            state[i][j] = temp[i][j];
        }
    }

    printState(state);
}

// AddRoundKey step
void AddRoundKey(uint8_t state[4][4], const uint8_t roundKey[4][4]) {
    cout << "\nAddRoundKey:\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            state[i][j] ^= roundKey[i][j];
        }
    }
    printState(state);
}

// Key expansion function
void KeyExpansion(const uint8_t key[4][4], uint8_t roundKeys[11][4][4]) {
    // Define constants
    const uint8_t Rcon[11] = {0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36};

    // Copy the original key into the first round key
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            roundKeys[0][i][j] = key[i][j];
        }
    }

    // Generate round keys
    for (int round = 1; round < 11; ++round) {
        uint8_t temp[4];

        // Rotate the previous key
        for (int i = 0; i < 4; ++i) {
            temp[i] = roundKeys[round - 1][(i + 1) % 4][3];
        }

        // Apply S-box to the first byte of the temp
        temp[0] = sbox[temp[0]];

        // XOR with Rcon
        temp[0] ^= Rcon[round];

        // Generate the new key
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (j == 0) {
                    roundKeys[round][i][j] = roundKeys[round - 1][i][j] ^ temp[i];
                } else {
                    roundKeys[round][i][j] = roundKeys[round][i][j - 1] ^ roundKeys[round - 1][i][j];
                }
            }
        }
    }
}

// AES encryption process
void AES_Encrypt(uint8_t state[4][4], const uint8_t roundKeys[11][4][4]) {
    cout << "\n========== Initial State ==========\n\n";
    printState(state);

    // Initial round key addition
    AddRoundKey(state, roundKeys[0]);

    // Main rounds
    for (int round = 1; round < 10; ++round) {
        cout << "\n========== Round " << round << " ==========\n";
        SubBytes(state);
        ShiftRows(state);
        MixColumns(state);
        AddRoundKey(state, roundKeys[round]);
    }

    // Final round
    cout << "\n========== Final Round ==========\n";
    SubBytes(state);
    ShiftRows(state);
    AddRoundKey(state, roundKeys[10]);

    cout << "\nEncrypted State:\n";
    printState(state);
}

void getUserInput(uint8_t array[4][4], const string &label) {
    cout << "Enter " << label << " in hexadecimal format (16 bytes as 2-digit hex each, e.g., 20 for 0x20):\n"; //20 5a 00 44 23 bb 11 55 03 bb 11 55 03 cc 22 66 55 dd 33 77
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int value;
            cin >> hex >> value;
            array[i][j] = static_cast<uint8_t>(value);
        }
    }
}
