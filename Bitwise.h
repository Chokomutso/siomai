// Function to convert binary string to integer
int binToDecimal(const string &binary) {
    int decimalValue = 0;
    for (size_t i = 0; i < binary.length(); ++i) {
        if (binary[binary.length() - 1 - i] == '1') {
            decimalValue += (1 << i); // Use bit shifting instead of stoi
        }
    }
    return decimalValue;
}

// Function to convert integer to binary string
string intToBinary(int number) {
    if (number == 0) return "0"; // Handle zero case
    string binary = "";
    while (number > 0) {
        binary = (number % 2 == 0 ? '0' : '1') + binary;
        number /= 2;
    }
    return binary;
}

// Function to convert binary fraction to decimal
double binaryFractionToDecimal(const string &binary) {
    size_t point = binary.find('.');
    if (point == string::npos) {
        return static_cast<double>(binaryToDecimal(binary)); // No fractional part
    }

    // Convert integer part
    string intPart = binary.substr(0, point);
    int intDecimal = binaryToDecimal(intPart);

    // Convert fractional part
    double fracDecimal = 0.0;
    string fracPart = binary.substr(point + 1);
    for (size_t i = 0; i < fracPart.length(); ++i) {
        if (fracPart[i] == '1') {
            fracDecimal += 1.0 / (1 << (i + 1)); // Each bit represents a power of 2
        }
    }

    return intDecimal + fracDecimal;
}

// Function to perform bitwise AND on two binary fractions
string bitwiseAnd(const string &bin1, const string &bin2) {
    // Split binary fractions into integer and fractional parts
    size_t point1 = bin1.find('.');
    size_t point2 = bin2.find('.');

    // Get integer and fractional parts
    string intPart1 = bin1.substr(0, point1);
    string fracPart1 = (point1 != string::npos) ? bin1.substr(point1 + 1) : "0";

    string intPart2 = bin2.substr(0, point2);
    string fracPart2 = (point2 != string::npos) ? bin2.substr(point2 + 1) : "0";

    // Convert integer parts to decimal
    int int1 = binaryToDecimal(intPart1);
    int int2 = binaryToDecimal(intPart2);

    // Perform bitwise AND on integer parts
    int intResult = int1 & int2;

    // Prepare the result for the fractional part
    string fracResult;
    size_t maxFracLength = max(fracPart1.length(), fracPart2.length());

    // Align fractional parts to the right
    fracPart1.append(maxFracLength - fracPart1.length(), '0');
    fracPart2.append(maxFracLength - fracPart2.length(), '0');

    // Perform bitwise AND on fractional parts
    for (size_t i = 0; i < maxFracLength; ++i) {
        if (fracPart1[i] == '1' && fracPart2[i] == '1') {
            fracResult += '1';
        } else {
            fracResult += '0';
        }
    }

    // Remove trailing zeros from the fractional result
    while (fracResult.length() > 1 && fracResult[fracResult.length() - 1] == '0') {
        fracResult = fracResult.substr(0, fracResult.length() - 1);
    }

    // Handle the case where the fractional part results in an empty string
    if (fracResult.empty() || (fracResult == "0")) {
        fracResult = "0";
    }

    // Combine results into a single binary fraction
    return intToBinary(intResult) + "." + fracResult;
}

// Function to perform bitwise OR on two binary fractions
string bitwiseOr(const string &bin1, const string &bin2) {
    size_t point1 = bin1.find('.');
    size_t point2 = bin2.find('.');

    string intPart1 = bin1.substr(0, point1);
    string fracPart1 = (point1 != string::npos) ? bin1.substr(point1 + 1) : "0";

    string intPart2 = bin2.substr(0, point2);
    string fracPart2 = (point2 != string::npos) ? bin2.substr(point2 + 1) : "0";

    // Convert integer parts to decimal
    int int1 = binaryToDecimal(intPart1);
    int int2 = binaryToDecimal(intPart2);

    // Perform bitwise OR on integer parts
    int intResult = int1 | int2;

    // Prepare the result for the fractional part
    string fracResult;
    size_t maxFracLength = max(fracPart1.length(), fracPart2.length());
    
    // Align fractional parts to the right
    fracPart1.append(maxFracLength - fracPart1.length(), '0');
    fracPart2.append(maxFracLength - fracPart2.length(), '0');

    // Perform bitwise OR on fractional parts
    for (size_t i = 0; i < maxFracLength; ++i) {
        if (fracPart1[i] == '1' || fracPart2[i] == '1') {
            fracResult += '1';
        } else {
            fracResult += '0';
        }
    }

    // Remove trailing zeros from the fractional result
    while (fracResult.length() > 1 && fracResult[fracResult.length() - 1] == '0') {
        fracResult = fracResult.substr(0, fracResult.length() - 1);
    }

    // Handle the case where the fractional part results in an empty string
    if (fracResult.empty() || (fracResult == "0")) {
        fracResult = "0";
    }

    // Combine results into a single binary fraction
    return intToBinary(intResult) + "." + fracResult;
}

// Function to perform bitwise XOR on two binary fractions
string bitwiseXor(const string &bin1, const string &bin2) {
    size_t point1 = bin1.find('.');
    size_t point2 = bin2.find('.');

    string intPart1 = bin1.substr(0, point1);
    string fracPart1 = (point1 != string::npos) ? bin1.substr(point1 + 1) : "0";

    string intPart2 = bin2.substr(0, point2);
    string fracPart2 = (point2 != string::npos) ? bin2.substr(point2 + 1) : "0";

    // Convert integer parts to decimal
    int int1 = binaryToDecimal(intPart1);
    int int2 = binaryToDecimal(intPart2);

    // Perform bitwise XOR on integer parts
    int intResult = int1 ^ int2;

    // Prepare the result for the fractional part
    string fracResult;
    size_t maxFracLength = max(fracPart1.length(), fracPart2.length());
    
    // Align fractional parts to the right
    fracPart1.append(maxFracLength - fracPart1.length(), '0');
    fracPart2.append(maxFracLength - fracPart2.length(), '0');

    // Perform bitwise XOR on fractional parts
    for (size_t i = 0; i < maxFracLength; ++i) {
        if ((fracPart1[i] == '1' && fracPart2[i] == '0') || (fracPart1[i] == '0' && fracPart2[i] == '1')) {
            fracResult += '1';
        } else {
            fracResult += '0';
        }
    }

    // Remove trailing zeros from the fractional result
    while (fracResult.length() > 1 && fracResult[fracResult.length() - 1] == '0') {
        fracResult = fracResult.substr(0, fracResult.length() - 1);
    }

    // Handle the case where the fractional part results in an empty string
    if (fracResult.empty() || (fracResult == "0")) {
        fracResult = "0";
    }

    // Combine results into a single binary fraction
    return intToBinary(intResult) + "." + fracResult;
}

// Function to perform bitwise NOT on a binary fraction
string bitwiseNot(const string &bin) {
    size_t point = bin.find('.');
    
    string intPart = bin.substr(0, point);
    string fracPart = (point != string::npos) ? bin.substr(point + 1) : "0";

    // Perform bitwise NOT on the integer part
    string intResult = "";
    for (size_t i = 0; i < intPart.length(); ++i) {
        intResult += (intPart[i] == '1') ? '0' : '1';
    }

    // Perform bitwise NOT on the fractional part
    string fracResult = "";
    for (size_t i = 0; i < fracPart.length(); ++i) {
        fracResult += (fracPart[i] == '1') ? '0' : '1';
    }

    // Remove trailing zeros from the fractional result
    while (fracResult.length() > 1 && fracResult[fracResult.length() - 1] == '0') {
        fracResult = fracResult.substr(0, fracResult.length() - 1);
    }

    // Handle the case where the fractional part results in an empty string
    if (fracResult.empty() || (fracResult == "0")) {
        fracResult = "0";
    }

    // Combine results into a single binary fraction
    return intResult + "." + fracResult;
}
