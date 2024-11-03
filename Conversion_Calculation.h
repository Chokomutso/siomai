using namespace std;

// ================== Conversion Functions ==================

// Split input into integer and fractional parts
void splitParts(const string &input, string &intPart, string &fracPart) {
    size_t pos = input.find('.');
    if (pos != string::npos) {
        intPart = input.substr(0, pos);  // part before '.'
        fracPart = input.substr(pos + 1); // part after '.'
    } else {
        intPart = input;
        fracPart = "";
    }
}

// Convert integer to string
string intToString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

// Binary to Decimal conversion
double binaryToDecimal(const string &bin) {
    string intPart, fracPart;
    splitParts(bin, intPart, fracPart);

    // Process integer part
    int decIntPart = 0;
    for (size_t i = 0; i < intPart.length(); i++) {
        decIntPart = decIntPart * 2 + (intPart[i] - '0');
    }

    // Process fractional part
    double decFracPart = 0.0;
    double fracBase = 0.5;
    for (size_t i = 0; i < fracPart.length(); i++) {
        decFracPart += (fracPart[i] - '0') * fracBase;
        fracBase /= 2;
    }

    return decIntPart + decFracPart;
}

// Binary to Octal conversion
string binaryToOctal(const string &bin) {
    double decimal = binaryToDecimal(bin);
    int intPart = static_cast<int>(decimal);
    double fracPart = decimal - intPart;

    // Convert integer part to octal
    string octalIntPart;
    do {
        octalIntPart = intToString(intPart % 8) + octalIntPart;
        intPart /= 8;
    } while (intPart > 0);

    // Convert fractional part to octal
    string octalFracPart;
    int maxPrecision = 6;  // Limit precision to 6 digits
    int precisionCount = 0;

    while (fracPart > 0 && precisionCount < maxPrecision) {
        fracPart *= 8;
        int octDigit = static_cast<int>(fracPart);
        octalFracPart += intToString(octDigit);
        fracPart -= octDigit;
        precisionCount++;
    }

    // Combine integer and fractional parts
    if (!octalFracPart.empty()) {
        return octalIntPart + "." + octalFracPart;
    } else {
        return octalIntPart;  // No fractional part
    }
}

// Binary to Hexadecimal conversion
string binaryToHex(const string &bin) {
    double decimal = binaryToDecimal(bin);
    int intPart = static_cast<int>(decimal);
    double fracPart = decimal - intPart;

    // Convert integer part to hexadecimal
    string hexIntPart;
    char hexDigits[] = "0123456789ABCDEF";
    do {
        hexIntPart = hexDigits[intPart % 16] + hexIntPart;
        intPart /= 16;
    } while (intPart > 0);

    // Convert fractional part to hexadecimal
    string hexFracPart;
    int maxPrecision = 6;  // Limit precision to 6 digits to avoid infinite loops
    int precisionCount = 0;

    while (fracPart > 0 && precisionCount < maxPrecision) {
        fracPart *= 16;
        int hexDigit = static_cast<int>(fracPart);
        hexFracPart += hexDigits[hexDigit];
        fracPart -= hexDigit;
        precisionCount++;
    }

    // Combine integer and fractional parts
    if (!hexFracPart.empty()) {
        return hexIntPart + "." + hexFracPart;
    } else {
        return hexIntPart;  // No fractional part
    }
}

// Decimal to Binary conversion
string decimalToBinary(double dec) {
    int intPart = static_cast<int>(dec);
    double fracPart = dec - intPart;

    // Convert integer part to binary
    string binaryIntPart;
    do {
        binaryIntPart = intToString(intPart % 2) + binaryIntPart;
        intPart /= 2;
    } while (intPart > 0);

    // Convert fractional part to binary
    string binaryFracPart;
    for (int i = 0; i < 6 && fracPart > 0; i++) { // Limit fraction to 6 bits
        fracPart *= 2;
        int fracBit = static_cast<int>(fracPart);
        binaryFracPart += intToString(fracBit);
        fracPart -= fracBit;
    }

    return binaryIntPart + (binaryFracPart.empty() ? "" : "." + binaryFracPart);
}

// Decimal to Octal conversion
string decimalToOctal(double dec) {
    int intPart = static_cast<int>(dec);
    double fracPart = dec - intPart;

    // Convert integer part to octal
    string octalIntPart;
    do {
        octalIntPart = intToString(intPart % 8) + octalIntPart;
        intPart /= 8;
    } while (intPart > 0);

    // Convert fractional part to octal
    string octalFracPart;
    int maxPrecision = 6;  // Limit precision to avoid infinite loops
    int precisionCount = 0;

    while (fracPart > 0 && precisionCount < maxPrecision) {
        fracPart *= 8;
        int octDigit = static_cast<int>(fracPart);
        octalFracPart += intToString(octDigit);
        fracPart -= octDigit;
        precisionCount++;
    }

    // Combine integer and fractional parts
    if (!octalFracPart.empty()) {
        return octalIntPart + "." + octalFracPart;
    } else {
        return octalIntPart;
    }
}

// Decimal to Hexadecimal conversion
string decimalToHex(double dec) {
    long long intPart = static_cast<long long>(dec);
    double fracPart = dec - intPart;

    // Convert integer part to hexadecimal
    string hexIntPart;
    char hexDigits[] = "0123456789ABCDEF";
    do {
        hexIntPart = hexDigits[intPart % 16] + hexIntPart;
        intPart /= 16;
    } while (intPart > 0);

    // Convert fractional part to hexadecimal
    string hexFracPart;
    int maxPrecision = 8;  // Limit precision to 8 digits to avoid infinite loops
    int precisionCount = 0;

    while (fracPart > 0 && precisionCount < maxPrecision) {
        fracPart *= 16;
        int hexDigit = static_cast<int>(fracPart);
        hexFracPart += hexDigits[hexDigit];
        fracPart -= hexDigit;
        precisionCount++;
    }

    // Combine integer and fractional parts
    if (!hexFracPart.empty()) {
        return hexIntPart + "." + hexFracPart;
    } else {
        return hexIntPart;  // No fractional part
    }
}

// Octal to Binary conversion
string octalToBinary(const string &oct) {
    string intPart, fracPart;
    splitParts(oct, intPart, fracPart);

    // Convert integer part
    string binaryIntPart;
    for (size_t i = 0; i < intPart.length(); i++) {
        char ch = intPart[i];
        int octDigit = ch - '0';
        binaryIntPart += bitset<3>(octDigit).to_string(); // Convert each digit to a 3-bit binary
    }

    // Convert fractional part
    string binaryFracPart;
    for (size_t i = 0; i < fracPart.length(); i++) {
        char ch = fracPart[i];
        int octDigit = ch - '0';
        binaryFracPart += bitset<3>(octDigit).to_string(); // Convert each digit to a 3-bit binary
    }

    return binaryIntPart + (binaryFracPart.empty() ? "" : "." + binaryFracPart);
}

// Octal to Decimal conversion
double octalToDecimal(const string &oct) {
    string intPart, fracPart;
    splitParts(oct, intPart, fracPart);

    // Convert integer part
    int decIntPart = 0;
    for (size_t i = 0; i < intPart.length(); i++) {
        decIntPart = decIntPart * 8 + (intPart[i] - '0');
    }

    // Convert fractional part
    double decFracPart = 0.0;
    double fracBase = 1.0 / 8.0;
    for (size_t i = 0; i < fracPart.length(); i++) {
        decFracPart += (fracPart[i] - '0') * fracBase;
        fracBase /= 8.0;
    }

    return decIntPart + decFracPart;
}

// Hexadecimal to Binary conversion
string hexToBinary(const string &hex) {
    string intPart, fracPart;
    splitParts(hex, intPart, fracPart);

    // Convert integer part
    string binaryIntPart;
    for (size_t i = 0; i < intPart.length(); i++) {
        int hexDigit;
        if (intPart[i] >= '0' && intPart[i] <= '9')
            hexDigit = intPart[i] - '0';
        else
            hexDigit = toupper(intPart[i]) - 'A' + 10;

        // Convert hex digit to binary and preserve 4 bits
        string bin = bitset<4>(hexDigit).to_string();
        binaryIntPart += bin;
    }

    // Remove leading zeros from the integer part (except the last zero if all are zero)
    size_t first_one = binaryIntPart.find('1');
    if (first_one != string::npos)
        binaryIntPart = binaryIntPart.substr(first_one);
    else
        binaryIntPart = "0";

    // Convert fractional part
    string binaryFracPart;
    for (size_t i = 0; i < fracPart.length(); i++) {
        int hexDigit;
        if (fracPart[i] >= '0' && fracPart[i] <= '9')
            hexDigit = fracPart[i] - '0';
        else
            hexDigit = toupper(fracPart[i]) - 'A' + 10;

        // Convert hex digit to binary and preserve 4 bits
        binaryFracPart += bitset<4>(hexDigit).to_string();
    }

    // Return the result
    return binaryIntPart + (binaryFracPart.empty() ? "" : "." + binaryFracPart);
}

// Hexadecimal to Decimal conversion
double hexToDecimal(const string &hex) {
    string intPart, fracPart;
    splitParts(hex, intPart, fracPart);

    // Convert integer part
    long long decIntPart = 0;
    for (size_t i = 0; i < intPart.length(); i++) {
        int hexDigit;
        if (intPart[i] >= '0' && intPart[i] <= '9')
            hexDigit = intPart[i] - '0';
        else
            hexDigit = toupper(intPart[i]) - 'A' + 10;
        decIntPart = decIntPart * 16 + hexDigit;
    }

    // Convert fractional part
    double decFracPart = 0.0;
    double fracBase = 1.0 / 16.0;
    for (size_t i = 0; i < fracPart.length(); i++) {
        int hexDigit;
        if (fracPart[i] >= '0' && fracPart[i] <= '9')
            hexDigit = fracPart[i] - '0';
        else
            hexDigit = toupper(fracPart[i]) - 'A' + 10;
        decFracPart += hexDigit * fracBase;
        fracBase /= 16.0;
    }

    return decIntPart + decFracPart;
}

// ================== Calculator Functions ==================

// Binary Arithmetic Operations
string binaryAddition(string bin1, string bin2) {
    double dec1 = binaryToDecimal(bin1);
    double dec2 = binaryToDecimal(bin2);
    double sum = dec1 + dec2;
    return decimalToBinary(sum);
}

string binarySubtraction(string bin1, string bin2) {
    double dec1 = binaryToDecimal(bin1);
    double dec2 = binaryToDecimal(bin2);
    double diff = dec1 - dec2;
    if (diff < 0)
        return "Error: Negative result!";
    return decimalToBinary(diff);
}

string binaryMultiplication(string bin1, string bin2) {
    double dec1 = binaryToDecimal(bin1);
    double dec2 = binaryToDecimal(bin2);
    double product = dec1 * dec2;
    return decimalToBinary(product);
}

string binaryDivision(string bin1, string bin2) {
    double dec1 = binaryToDecimal(bin1);
    double dec2 = binaryToDecimal(bin2);
    if (dec2 == 0)
        return "Error: Division by zero!";
    double quotient = dec1 / dec2;
    return decimalToBinary(quotient);
}

// Octal Arithmetic Operations
string octalAddition(string oct1, string oct2) {
    double dec1 = octalToDecimal(oct1);
    double dec2 = octalToDecimal(oct2);
    double sum = dec1 + dec2;
    return decimalToOctal(sum);
}

string octalSubtraction(string oct1, string oct2) {
    double dec1 = octalToDecimal(oct1);
    double dec2 = octalToDecimal(oct2);
    double diff = dec1 - dec2;
    if (diff < 0)
        return "Error: Negative result!";
    return decimalToOctal(diff);
}

string octalMultiplication(string oct1, string oct2) {
    double dec1 = octalToDecimal(oct1);
    double dec2 = octalToDecimal(oct2);
    double product = dec1 * dec2;
    return decimalToOctal(product);
}

string octalDivision(string oct1, string oct2) {
    double dec1 = octalToDecimal(oct1);
    double dec2 = octalToDecimal(oct2);
    if (dec2 == 0)
        return "Error: Division by zero!";
    double quotient = dec1 / dec2;
    return decimalToOctal(quotient);
}

// Hexadecimal Arithmetic Operations
string hexAddition(string hex1, string hex2) {
    double dec1 = hexToDecimal(hex1);
    double dec2 = hexToDecimal(hex2);
    double sum = dec1 + dec2;
    return decimalToHex(sum);
}

string hexSubtraction(string hex1, string hex2) {
    double dec1 = hexToDecimal(hex1);
    double dec2 = hexToDecimal(hex2);
    double diff = dec1 - dec2;
    if (diff < 0)
        return "Error: Negative result!";
    return decimalToHex(diff);
}

string hexMultiplication(string hex1, string hex2) {
    double dec1 = hexToDecimal(hex1);
    double dec2 = hexToDecimal(hex2);
    double product = dec1 * dec2;
    return decimalToHex(product);
}

string hexDivision(string hex1, string hex2) {
    double dec1 = hexToDecimal(hex1);
    double dec2 = hexToDecimal(hex2);
    if (dec2 == 0)
        return "Error: Division by zero!";
    double quotient = dec1 / dec2;
    return decimalToHex(quotient);
}
