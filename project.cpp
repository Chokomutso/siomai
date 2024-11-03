#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <sstream>
#include <bitset>
#include "Conversion_Calculation.h"
#include "PrimeNumbers_Factorization.h"
#include "Bitwise.h"
#include "ModArithmetic.h"
#include "AES.h"
#include "DES.h"
#include "GreedyAlgo.h"

using namespace std;

// ================== Main Function ==================

int main(){
    char key1, key2, key3;
    string binInput, octInput, hexInput;
    double decInput;
    bool exitProgram = false;
    bool backmenu = false;
    
    while(!exitProgram){
	    cout << "=============== Menu ===============\n\n"
	         << "[1] Conversion\n"
	         << "[2] Calculator\n"
	         << "[3] Sieve of Erastostenes\n"
	         << "[4] Prime Factorization\n"
	         << "[5] LCM/GCD\n"
	         << "[6] Euclidean Algorithm\n"
	         << "[7] Fibonachi Secquence\n"
	         << "[8] Bitwise Operation\n"
	         << "[9] More\n"
	         << "[0] Exit\n\n"
	         << "Choose a number: ";
	    cin >> key1;
	    
	    switch(key1){
	        case '1':
	            system("cls");
	            cout << "=============== Conversion ===============\n\n"
	                 << "[0] Binary To Decimal\n"
	                 << "[1] Binary To Octal\n"
	                 << "[2] Binary To Hexadecimal\n"
	                 << "[3] Decimal To Binary\n"
	                 << "[4] Decimal To Octal\n"
	                 << "[5] Decimal To Hexadecimal\n"
	                 << "[6] Octal To Binary\n"
	                 << "[7] Octal To Decimal\n"
	                 << "[8] Hexadecimal To Binary\n"
	                 << "[9] Hexadecimal To Decimal\n"
	                 << "[m] Menu\n\n"
	                 << "Choose a number: ";
	            cin >> key2;
	            
	            switch(key2){
	                case '0':
	                    system("cls");
	                    cout << "=============== Binary To Decimal ===============\n\n";
	                    cout << "Enter Binary Number: ";
	                    cin >> binInput;
	                    cout << "The decimal equivalent is: " << binaryToDecimal(binInput) << endl;
	                    break;
	                case '1':
	                    system("cls");
	                    cout << "=============== Binary To Octal ===============\n\n";
	                    cout << "Enter Binary Number: ";
	                    cin >> binInput;
	                    cout << "The octal equivalent is: " << binaryToOctal(binInput) << endl;
	                    break;
	                case '2':
	                    system("cls");
	                    cout << "=============== Binary To Hexadecimal ===============\n\n";
	                    cout << "Enter Binary Number: ";
	                    cin >> binInput;
	                    cout << "The hexadecimal equivalent is: " << binaryToHex(binInput) << endl;
	                    break;
	                case '3':
	                    system("cls");
	                    cout << "=============== Decimal To Binary ===============\n\n";
	                    cout << "Enter Decimal Number: ";
	                    cin >> decInput;
	                    cout << "The binary equivalent is: " << decimalToBinary(decInput) << endl;
	                    break;
	                case '4':
	                    system("cls");
	                    cout << "=============== Decimal To Octal ===============\n\n";
	                    cout << "Enter Decimal Number: ";
	                    cin >> decInput;
	                    cout << "The octal equivalent is: " << decimalToOctal(decInput) << endl;
	                    break;
	                case '5':
	                    system("cls");
	                    cout << "=============== Decimal To Hexadecimal ===============\n\n";
	                    cout << "Enter Decimal Number: ";
	                    cin >> decInput;
	                    cout << "The hexadecimal equivalent is: " << decimalToHex(decInput) << endl;
	                    break;
	                case '6':
	                    system("cls");
	                    cout << "=============== Octal To Binary ===============\n\n";
	                    cout << "Enter Octal Number: ";
	                    cin >> octInput;
	                    cout << "The binary equivalent is: " << octalToBinary(octInput) << endl;
	                    break;
	                case '7':{
	                    system("cls");
	                    cout << "=============== Octal To Decimal ===============\n\n";
	                    cout << "Enter Octal Number: ";
	                    cin >> octInput;
	                    double decValue = octalToDecimal(octInput);
	                    cout << "The decimal equivalent is: " << fixed << setprecision(10) << decValue << endl;
	                    break;
	                }
	                case '8':
	                    system("cls");
	                    cout << "=============== Hexadecimal To Binary ===============\n\n";
	                    cout << "Enter Hexadecimal Number: ";
	                    cin >> hexInput;
	                    cout << "The binary equivalent is: " << hexToBinary(hexInput) << endl;
	                    break;
	                case '9':{    
	                    system("cls");
	                    cout << "=============== Hexadecimal To Decimal ===============\n\n";
	                    cout << "Enter Hexadecimal Number: ";
	                    cin >> hexInput;
	                    double decValue = hexToDecimal(hexInput);
	                    cout << "The decimal equivalent is: " << fixed << setprecision(10) << decValue << endl;
	                    break;
	                }
	                case 'M':
	                case 'm':
	                    system("cls");
	                    return main();
	                    break;
	                default:
	                    cout << "\nInvalid Choice!\n";
	                    break;
	            }
	            break;
	            
	        case '2':
	            system("cls");
	            cout << "=============== Calculator ===============\n\n"
	                 << "[1] Binary Calculator\n"
	                 << "[2] Octal Calculator\n"
	                 << "[3] Hexadecimal Calculator\n"
	                 << "[0] Menu\n\n"
	                 << "Choose a number: ";
	            cin >> key2;
	            
	            switch(key2){
	                case '1':
	                    system("cls");
	                    cout << "=============== Binary Calculator ===============\n\n"
	                         << "[1] Addition\n"
	                         << "[2] Subtraction\n"
	                         << "[3] Multiplication\n"
	                         << "[4] Division\n\n"
	                         << "Choose operation: ";
	                    cin >> key3;
	                    
	                    switch(key3){
	                        case '1': {
	                            string bin1, bin2, result;
	                            system("cls");
	                            cout << "=============== Binary Addition ===============\n\n";
	                            cout << "Enter first binary number: ";
	                            cin >> bin1;
	                            cout << "Enter second binary number: ";
	                            cin >> bin2;
	                            result = binaryAddition(bin1, bin2);
	                            cout << "Result: " << result << endl;
	                            break;
	                        }
	                        case '2': {
	                            string bin1, bin2, result;
	                            system("cls");
	                            cout << "=============== Binary Subtraction ===============\n\n";
	                            cout << "Enter first binary number: ";
	                            cin >> bin1;
	                            cout << "Enter second binary number: ";
	                            cin >> bin2;
	                            result = binarySubtraction(bin1, bin2);
	                            cout << "Result: " << result << endl;
	                            break;
	                        }
	                        case '3': {
	                            string bin1, bin2, result;
	                            system("cls");
	                            cout << "=============== Binary Multiplication ===============\n\n";
	                            cout << "Enter first binary number: ";
	                            cin >> bin1;
	                            cout << "Enter second binary number: ";
	                            cin >> bin2;
	                            result = binaryMultiplication(bin1, bin2);
	                            cout << "Result: " << result << endl;
	                            break;
	                        }
	                        case '4': {
	                            string bin1, bin2, result;
	                            system("cls");
	                            cout << "=============== Binary Division ===============\n\n";
	                            cout << "Enter first binary number: ";
	                            cin >> bin1;
	                            cout << "Enter second binary number: ";
	                            cin >> bin2;
	                            result = binaryDivision(bin1, bin2);
	                            cout << "Result: " << result << endl;
	                            break;
	                        }
	                        default:
	                            cout << "\nInvalid Choice!\n";
	                    }
	                    
	                    break;
	                case '2':
	                    system("cls");
	                    cout << "=============== Octal Calculator ===============\n\n"
	                         << "[1] Addition\n"
	                         << "[2] Subtraction\n"
	                         << "[3] Multiplication\n"
	                         << "[4] Division\n\n"
	                         << "Choose operation: ";
	                    cin >> key3;
	                    
	                    switch(key3){
	                        case '1': {
	                            string oct1, oct2, result;
	                            system("cls");
	                            cout << "=============== Octal Addition ===============\n\n";
	                            cout << "Enter first octal number: ";
	                            cin >> oct1;
	                            cout << "Enter second octal number: ";
	                            cin >> oct2;
	                            result = octalAddition(oct1, oct2);
	                            cout << "Result: " << result << endl;
	                            break;
	                        }
	                        case '2': {
	                            string oct1, oct2, result;
	                            system("cls");
	                            cout << "=============== Octal Subtraction ===============\n\n";
	                            cout << "Enter first octal number: ";
	                            cin >> oct1;
	                            cout << "Enter second octal number: ";
	                            cin >> oct2;
	                            result = octalSubtraction(oct1, oct2);
	                            cout << "Result: " << result << endl;
	                            break;
	                        }
	                        case '3': {
	                            string oct1, oct2, result;
	                            system("cls");
	                            cout << "=============== Octal Multiplication ===============\n\n";
	                            cout << "Enter first octal number: ";
	                            cin >> oct1;
	                            cout << "Enter second octal number: ";
	                            cin >> oct2;
	                            result = octalMultiplication(oct1, oct2);
	                            cout << "Result: " << result << endl;
	                            break;
	                        }
	                        case '4': {
	                            string oct1, oct2, result;
	                            system("cls");
	                            cout << "=============== Octal Division ===============\n\n";
	                            cout << "Enter first octal number: ";
	                            cin >> oct1;
	                            cout << "Enter second octal number: ";
	                            cin >> oct2;
	                            result = octalDivision(oct1, oct2);
	                            cout << "Result: " << result << endl;
	                            break;
	                        }
	                        default:
	                            cout << "\nInvalid Choice!\n";
	                    }
	                    
	                    break;
	                case '3':
	                    system("cls");
	                    cout << "=============== Hexadecimal Calculator ===============\n\n"
	                         << "[1] Addition\n"
	                         << "[2] Subtraction\n"
	                         << "[3] Multiplication\n"
	                         << "[4] Division\n\n"
	                         << "Choose operation: ";
	                    cin >> key3;
	                    
	                    switch(key3){
	                        case '1': {
	                            string hex1, hex2, result;
	                            system("cls");
	                            cout << "=============== Hexadecimal Addition ===============\n\n";
	                            cout << "Enter first hexadecimal number: ";
	                            cin >> hex1;
	                            cout << "Enter second hexadecimal number: ";
	                            cin >> hex2;
	                            result = hexAddition(hex1, hex2);
	                            cout << "Result: " << result << endl;
	                            break;
	                        }
	                        case '2': {
	                            string hex1, hex2, result;
	                            system("cls");
	                            cout << "=============== Hexadecimal Subtraction ===============\n\n";
	                            cout << "Enter first hexadecimal number: ";
	                            cin >> hex1;
	                            cout << "Enter second hexadecimal number: ";
	                            cin >> hex2;
	                            result = hexSubtraction(hex1, hex2);
	                            cout << "Result: " << result << endl;
	                            break;
	                        }
	                        case '3': {
	                            string hex1, hex2, result;
	                            system("cls");
	                            cout << "=============== Hexadecimal Multiplication ===============\n\n";
	                            cout << "Enter first hexadecimal number: ";
	                            cin >> hex1;
	                            cout << "Enter second hexadecimal number: ";
	                            cin >> hex2;
	                            result = hexMultiplication(hex1, hex2);
	                            cout << "Result: " << result << endl;
	                            break;
	                        }
	                        case '4': {
	                            string hex1, hex2, result;
	                            system("cls");
	                            cout << "=============== Hexadecimal Division ===============\n\n";
	                            cout << "Enter first hexadecimal number: ";
	                            cin >> hex1;
	                            cout << "Enter second hexadecimal number: ";
	                            cin >> hex2;
	                            result = hexDivision(hex1, hex2);
	                            cout << "Result: " << result << endl;
	                            break;
	                        }
	                        default:
	                            cout << "\nInvalid Choice!\n";
	                    }
	                    
	                    break;
	                case '0':
	                    system("cls");
	                    return main();
	                default:
	                    cout << "\nInvalid Choice!\n";
	                    break;
	            }
	            
	            break;
	            
	    	case '3':{
    				system("cls");
					int n;
					cout << "=============== Sieve of Eratosthenes ===============\n\n";
				    cout << "Enter Number: ";
				    cin >> n;
				    cout << "Following are the prime numbers smaller "
				         << "than or equal to " << n << ":" << endl;
				    SieveOfEratosthenes(n);
					break;
				}
				
			case '4':{
				system("cls");
				int n; 
    			cout << "=============== Prime Factorization ===============\n\n";
			    cout << "Enter number: ";
			    cin >> n;
			    cout << "The factors of " << n << " are: ";
			    primeFactors(n); 
			    cout << endl;
				break;
			}
			
			case '5':{
				system("cls");
			    int num1, num2;
			    cout << "=============== LCM/GCD ===============\n\n";
			    cout << "Enter Num1: ";
			    cin >> num1;
			    cout << "Enter Num2: ";
			    cin >> num2;
			
			    
			    int gcdValue = gcd(num1, num2);
			    int lcmValue = (num1 * num2) / gcdValue;
			    
			    cout << "\nFactors of " << num1 << " = ";
			    primeFactors(num1);
			    cout << endl;
			
			    cout << "Factors of " << num2 << " = ";
			    primeFactors(num2);
			    cout << endl << endl;

			    cout << "LCM(" << num1 << "," << num2 << ") = " << lcmValue << endl;
			    cout << "GCD(" << num1 << "," << num2 << ") = " << gcdValue << endl;
			
			    break;
			}
			
			case '6':{
				system("cls");
				int num1,num2;
				cout << "=============== Euclidean Algorithm ===============\n\n";
				cout << "Enter Num1: ";
				cin >> num1;
				cout << "Enter Num2: ";
				cin >> num2;
   				
				cout << "\nGCD(" << num1 << "," << num2 << ") = " << gcd(num1, num2) << endl;
				break;
			}
			
			case '7':{
				system("cls");
				int n;
				cout << "=============== Fibonacci Secquence ===============\n\n";
			    cout << "Enter the number of terms: ";
			    cin >> n;
			
			    printFibonacci(n);
				break;
			}
			
			case '8':{
				system("cls");
				cout << "=============== Bitwise Operation ===============\n\n";
			    cout << "[1] AND\n"
					 << "[2] OR\n"
					 << "[3] XOR\n"
					 << "[4] NOT\n\n"
					 << "Choose a number: ";
				cin >> key2;
				
				switch(key2){
					case '1':{
						system("cls");
						cout << "=============== AND ===============\n\n";
						string binA, binB;
						cout << "Enter binary number A: ";
						cin >> binA;
						cout << "Enter binary number B: ";
						cin >> binB;
					    
					    // Perform bitwise AND operation
					    string result = bitwiseAnd(binA, binB);
					    
					    // Calculate decimal equivalents
					    double decimal1 = binaryFractionToDecimal(binA);
					    double decimal2 = binaryFractionToDecimal(binB);
					    double decimalResult = binaryFractionToDecimal(result);
					    
					    cout << "\nA: " << binA << " = " << decimal1 << endl;
					    cout << "B: " << binB << " = " << decimal2 << endl;
					    cout << "\nA&B: " << result << " = " << decimalResult << endl;
						break;
					}
					case '2':{
						system("cls");
						cout << "=============== OR ===============\n\n";
						string binA, binB;
						cout << "Enter binary number A: ";
						cin >> binA;
						cout << "Enter binary number B: ";
						cin >> binB;
						
					    // Perform bitwise OR operation
					    string result = bitwiseOr(binA, binB);
					    
					    // Calculate decimal equivalents
					    double decimal1 = binaryFractionToDecimal(binA);
					    double decimal2 = binaryFractionToDecimal(binB);
					    double decimalResult = binaryFractionToDecimal(result);
					    
					    cout << "\nA: " << binA << " = " << decimal1 << endl;
					    cout << "B: " << binB << " = " << decimal2 << endl;
					    cout << "\nA|B: " << result << " = " << decimalResult << endl;
						break;
					}
					case '3':{
						system("cls");
						cout << "=============== XOR ===============\n\n";
						string binA, binB;
						cout << "Enter binary number A: ";
						cin >> binA;
						cout << "Enter binary number B: ";
						cin >> binB;
					    
					    // Perform bitwise XOR operation
					    string result = bitwiseXor(binA, binB);
					    
					    // Calculate decimal equivalents
					    double decimal1 = binaryFractionToDecimal(binA);
					    double decimal2 = binaryFractionToDecimal(binB);
					    double decimalResult = binaryFractionToDecimal(result);
					    
					    cout << "\nA: " << binA << " = " << decimal1 << endl;
					    cout << "B: " << binB << " = " << decimal2 << endl;
					    cout << "\nA^B: " << result << " = " << decimalResult << endl;
						break;
					}
					case '4':{
						system("cls");
						cout << "=============== NOT ===============\n\n";
						string binA;
						cout << "Enter binary number A: ";
						cin >> binA;
					    
					    // Perform bitwise NOT operation
					    string result = bitwiseNot(binA);
					    
					    // Calculate decimal equivalents
					    double decimal1 = binaryFractionToDecimal(binA);
					    double decimalResult = binaryFractionToDecimal(result);
					    
					    cout << "\nA: " << binA << " = " << decimal1 << endl;
					    cout << "\nNOT A: " << result << " = " << decimalResult << endl;
						break;
					}
					default:{
						cout << "Invalid Choice!\n";
						break;
					}
				}
				break;
			}
			
			case '9':{
				system("cls");
				
					cout << "=============== Menu ===============\n\n"
					<< "[1] Egyptian Fraction\n"
					<< "[2] Modular Arithmetic\n"
					<< "[3] Caesar Cipher\n"
					<< "[4] Diffie-Hellman Algorithm\n"
					<< "[5] RSA\n"
					<< "[6] AES\n"
					<< "[7] DES\n"
					<< "[8] Greedy Algorithm\n"
					<< "[0] Back\n\n"
					<< "Choose a number: ";
					cin >> key1;
				    
				    switch(key1){
				    	case '1':{
				    		system("cls");
							cout << "=============== Egyptian Fraction ===============\n\n";
							int n1, n2;
							cout << "n1/n2\n";
							cout << "Enter n1: ";
							cin >> n1;
							cout << "Enter n2: ";
							cin >> n2;
							
							cout << endl << n1 << "/" << n2 << " = ";
							egyptianFraction(n1, n2);
							cout << endl;
							break;
						}
						case '2':{
				    		system("cls");
							cout << "=============== Modular Arithmetic ===============\n\n";
							int choice, mod;
						    cout << "Enter modulus: ";
						    cin >> mod;
						
						    cout << "\nChoose an operation:\n"
								 << "[1] Addition\n"
								 << "[2] Subtraction\n"
								 << "[3] Multiplication\n"
								 << "[4] Exponentiation\n"
								 << "[5] Division\n\n"
								 << "Choose a number: ";
						    cin >> choice;
						
						    if (choice >= 1 && choice <= 3) {
						        int n;
						        cout << "\nEnter number of values: ";
						        cin >> n;
						        vector<int> numbers(n);
						
						        // Prompt for each number individually based on the count
						        for (int i = 0; i < n; i++) {
						            cout << "\nEnter num" << i + 1 << ": ";
						            cin >> numbers[i];
						        }
						
						        if (choice == 1) {
						            cout << "\nModular Addition result: " << modAdd(numbers, mod) << endl;
						        } else if (choice == 2) {
						            cout << "\nModular Subtraction result: " << modSubtract(numbers, mod) << endl;
						        } else if (choice == 3) {
						            cout << "\nModular Multiplication result: " << modMultiply(numbers, mod) << endl;
						        }
						    } else if (choice == 4) {
						        int base, exponent;
						        cout << "\nEnter base: ";
						        cin >> base;
								cout << "Enter exponent: ";
								cin >> exponent;
						        cout << "Modular Exponentiation result: " << modExponent(base, exponent, mod) << endl;
						    } else if (choice == 5) {
						        int a, b;
						        cout << "Enter dividend and divisor: ";
						        cin >> a >> b;
						        cout << "Modular Division result: " << modDivide(a, b, mod) << endl;
						    }else{
						        cout << "Invalid choice.\n";
						    }

							break;
						}
						case '3':{
				    		system("cls");
							cout << "=============== Caesar Cipher ===============\n\n";
							cout << "[1] Encrypt\n"
								 << "[2] Decrypt\n\n"
								 << "Choose a number: ";
							cin >> key2;
							
							switch(key2){
								case '1':{
									string text;
								    int s;
								    cout << "\nEnter Text : ";
									cin >> text;
								    cout << "Shift: ";
									cin >> s;
									
    								cout << "\nEncrypted Text: " << encrypt(text, s) << endl;
									break;
								}
								case '2':{
									string text;
								    int s;
								    cout << "\nEnter Text : ";
									cin >> text;
								    cout << "Shift: ";
									cin >> s;
									s = s%26;
									
    								cout << "\nDecrypted Text: " << encrypt(text, 26-s) << endl;
									break;
								}
								default:{
									cout << "\nInvalid Choice!\n";
									break;
								}
							}
							break;
						}
						case '4':{
							system("cls");
							cout << "=============== Diffie-Hellman Algorithm ===============\n\n";
							long long int P,G,a,b;
	
							cout << "Enter The value of P: ";
							cin >> P;
						    cout << "Enter The value of G: ";
						    cin >> G;
						    cout << "Enter private key for Alice: ";
						    cin >> a;
						    cout << "Enter private key for Bob: ";
						    cin >> b;
						    
						    diffieHellmanKeyExchange(P,G,a,b);
							break;
						}
						case '5':{
							system("cls");
							cout << "=============== RSA ===============\n\n";
							int PT, p, q, e;

						    cout << "Enter PT(number): ";
						    cin >> PT;
						    cout << "Enter two prime numbers p and q:\n";
						    cout << "p: ";
						    cin >> p;
						    cout << "q: ";
						    cin >> q;
						    cout << "Enter a public key e: ";
						    cin >> e;
						
						    rsaEncryptionDecryption(PT, p, q, e);
							break;
						}
						case '6':{
							system("cls");
							cout << "=============== AES ===============\n\n";
							
							// Initialize state and key arrays
						    uint8_t state[4][4];
						    uint8_t key[4][4];
						
						    // Get user input for the plaintext and key
						    getUserInput(state, "plaintext");
						    getUserInput(key, "key");
						
						    // Example round keys
						    uint8_t roundKeys[11][4][4];
						    KeyExpansion(key, roundKeys); // Generate round keys
						
						    // Execute AES encryption
						    AES_Encrypt(state, roundKeys);
							break;
						}
						case '7':{
							system("cls");
							cout << "=============== DES ===============\n\n";
							
							string input,k0;
    
						    // Loop for plaintext input
						    while (true) {
						        cout << "Enter 8-bit plaintext (as a binary string, e.g., 11101101): ";
						        cin >> input;
						        
						        // Check input length
						        if (input.length() == 8 && input.find_first_not_of("01") == string::npos) {
						            break; // valid input, exit loop
						        } else {
						            cerr << "Invalid input. Please enter an 8-bit binary string." << endl;
						        }
						    }
						
						    // Loop for key input
						    while (true) {
						        cout << "Enter 10-bit key (as a binary string, e.g., 1100011110): ";
						        cin >> k0;
						        
						        // Check input length
						        if (k0.length() == 10 && k0.find_first_not_of("01") == string::npos) {
						            break; // valid input, exit loop
						        } else {
						            cerr << "Invalid input. Please enter a 10-bit binary string." << endl;
						        }
						    }
						    
						    bitset<8> plaintext(input); // Convert the input string to a bitset<8>
						    bitset<10> key(k0);
						
							cout << "\n======================== Encryption ========================\n\n";
						    cout << "Plaintext: " << plaintext << endl;
						    cout << "Key: " << key << endl;
						
						    bitset<8> roundKey1, roundKey2;
						    generateRoundKeys(key, roundKey1, roundKey2);
						
						    bitset<8> cipherText = simplifiedDES(plaintext, roundKey1, roundKey2);
						    cout << "\nFinal Cipher Text: " << cipherText << endl;
							break;
						}
						case '8':{
							system("cls");
							cout << "=============== Greedy Algorithm ===============\n\n"
								 << "[1] Activity Selection\n"
								 << "[2] Job Sequencing\n"
								 << "[3] Knapsack Problem\n"
								 << "[4] Huffman Coding\n"
								 << "[0] Menu\n\n"
								 << "Choose a number: ";
							cin >> key2;
							
							switch(key2){
								case '1':{
									system("cls");
									cout << "=============== Activity Selection ===============\n\n";
									int n;
								    cout << "Enter the number of activities: ";
								    cin >> n;
								
								    vector<int> s(n, -1), f(n, -1); // Initialize with -1 to indicate unfilled slots
								
								    displayTable(s, f, n); // Display initial table with placeholders
								
								    for (int i = 0; i < n; i++) {
								        cout << "\nInput start and finish for Activity " << i + 1 << ": ";
								        cin >> s[i] >> f[i];
								        
								        system("cls");
								        cout << "=============== Activity Selection ===============\n\n";
								        cout << "Number of activities: " << n << endl;
								        displayTable(s, f, n);
								    }
								
								    // Function call to print selected activities
								    printMaxActivities(s, f, n);
									break;
								}
								case '2':{
									system("cls");
									cout << "=============== Job Sequencing ===============\n\n";
									int n;
								    cout << "Enter the number of Jobs: ";
								    cin >> n;
								
								    vector<Job> jobs(n); // Initialize jobs vector
									displayTable(jobs, n);
									
								    // Gather job information
								    for (int i = 0; i < n; i++) {
								        cout << "\nInput profits and deadline for Job " << i + 1 << ": ";
								        cin >> jobs[i].profit >> jobs[i].dead;
								        jobs[i].id = i + 1; // Assign job ID starting from 1
								        
								        system("cls");
								        cout << "=============== Job Sequencing ===============\n\n";
								        cout << "Number of Jobs: " << n << endl;
								        displayTable(jobs, n);
								    }
								
								    // Function call to print selected activities
								    jobSequencing(jobs, n);
									
									break;
								}
								case '3':{
									system("cls");
									cout << "=============== Knapsack Problem ===============\n\n";
									int n;
								    cout << "Enter the number of Items: ";
								    cin >> n;
								
								    vector<Item> items(n); // Initialize items vector
								    displayTable(items, n);
								    
								    // Gather item information
								    for (int i = 0; i < n; i++) {
								        cout << "\nInput profit and weight for Item " << i + 1 << ": ";
								        cin >> items[i].profit >> items[i].weight;
								        items[i].id = i + 1; // Assign item ID starting from 1
								        
								        system("cls"); 
								        cout << "=============== Knapsack Problem ===============\n\n";
								        cout << "Number of Items: " << n << endl;
								        
								        displayTable(items, n);
								    }
								
								    // Calculate ratios for each item
								    system("cls"); 
								    cout << "Number of Items: " << n << endl;
								    calculateRatios(items);
								    displayTable(items, n);
								
								    int capacity;
								    cout << "\nEnter the capacity of the knapsack: ";
								    cin >> capacity;
								
								    // Calculate and display the maximum profit
								    double totalProfit = fractionalKnapsack(items, capacity);
								    cout << "\nMaximum Profit from selected items: " << totalProfit << endl;
									
									break;
								}
								case '4':{
									system("cls");
									cout << "============================== Huffman Coding ==============================\n\n";
									vector<pair<char, int> > frequencies; // Vector to store character and its frequency
								    char character;
								    int frequency;
								    
								    int n = 0; // Counter for number of characters
								    displayTable(frequencies, map<char, string>());
								    cout << "\nEnter character frequencies (enter '#' to stop):\n";
								    
								    while (true) {
								        n++; // Increment the number of characters
								        cout << "\nInput for Character " << n << ":\n";
								        
								        cout << "Character: ";
								        cin >> character;
								        if (character == '#') break; // Stop input on '#'
								
								        cout << "Frequency: ";
								        cin >> frequency;
								
								        frequencies.push_back(make_pair(character, frequency)); // Store as a pair
								
								        system("cls");
								        cout << "============================== Huffman Coding ==============================\n\n";
								        cout << "Number of characters: " << n << endl;
								
								        // Build Huffman tree
								        Node* root = buildHuffmanTree(frequencies);
								        map<char, string> huffmanCodes;
								        generateHuffmanCodes(root, "", huffmanCodes);
								        displayTable(frequencies, huffmanCodes);
								    }
								
								    // Build Huffman tree one last time
								    Node* root = buildHuffmanTree(frequencies);
								
								    // Generate Huffman codes
								    map<char, string> huffmanCodes;
								    generateHuffmanCodes(root, "", huffmanCodes);
								
								    // Output final table with Huffman codes
								    system("cls");
								    cout << "============================== Huffman Coding ==============================\n\n";
								    displayTable(frequencies, huffmanCodes);
								
								    // Clean up memory
								    deleteHuffmanTree(root);
									break;
								}
								case '0':{
									system("cls");
									return main();
									break;
								}
								default:{
									cout << "\nInvalid Choice!\n";
									break;
								}
							}
							break;
						}
						case '0':{
							system("cls");
							return main();
							break;
						}
						default:{
							cout << "\nInvalid Choice!\n";
							break;
						}
					}
				
				break;
			}
				
	        case '0':{
				exitProgram = true;
				system("cls");
				cout << "\nExiting Program. Goodbye!!\n";
				break;
			}
	        default:
	            cout << "\nInvalid Choice!\n";
	            break;
	    }
		
		if (!exitProgram) {
            cout << "\nPress Enter to return to the main menu...";
            cin.ignore(); 
            cin.get();
			system("cls");    
        }
	}
    return 0;
}

