#include <vector>
#include <algorithm>
#include <queue>
#include <map>

//=============== Activity Selection ===============
void displayTable(const vector<int>& s, const vector<int>& f, int n, int maxColumns = 6) {
    cout << "\nActivities Table:\n";
    
    for (int start = 0; start < n; start += maxColumns) {
        int end = min(start + maxColumns, n); // End column for the current row set

        cout << "+-----------+";
        for (int i = start; i < end; i++) cout << "-------+";
        cout << "\n";

        cout << "| Activity  |";
        for (int i = start; i < end; i++) {
            if (i + 1 >= 10){  
                cout << "   " << i + 1 << "  |";
        	}
			else{
                cout << "   " << i + 1 << "   |";
			}
        }
        cout << "\n";

        // Separator line
        cout << "+-----------+";
        for (int i = start; i < end; i++) cout << "-------+";
        cout << "\n";

        // Start time row
        cout << "| Start     |";
        for (int i = start; i < end; i++) {
            if (s[i] == -1){
                cout << "       |";  // Placeholder if not filled
			}
            else{
	            if (s[i] >= 10){  
	                cout << "   " << s[i] << "  |";
	        	}
				else{
                	cout << "   " << s[i] << "   |";
				}
			}
        }
        cout << "\n";

        // Separator line
        cout << "+-----------+";
        for (int i = start; i < end; i++) cout << "-------+";
        cout << "\n";

        // Finish time row
        cout << "| Finish    |";
        for (int i = start; i < end; i++) {
            if (f[i] == -1){
                cout << "       |";  
			}
            else{
            	if (f[i] >= 10){  
	                cout << "   " << f[i] << "  |";
	        	}
	        	else{
                cout << "   " << f[i] << "   |";
				}
			}
        }
        cout << "\n";

        // Bottom border of the current section
        cout << "+-----------+";
        for (int i = start; i < end; i++) cout << "-------+";
        cout << "\n";
    }
}

// Prints a maximum set of activities that can be done by a
// single person, one at a time.
void printMaxActivities(vector<int>& s, vector<int>& f, int n) {
    int i, j;
	int totalAct = 0;
	
    cout << "\nFollowing activities are selected:" << endl;

    i = 0;
    cout << "Activity " << i + 1 << ", ";
	totalAct++;

    // Consider rest of the activities
    for (j = 1; j < n; j++) {
        if (s[j] >= f[i]) {
            cout << "Activity " << j + 1 << " ";
            i = j;
            totalAct++;
        }
    }
    cout << endl;
    cout << "\nTotal Activities: " << totalAct << endl;
}


//=============== Job Sequencing ===============
// Structure to represent a job
struct Job {
    int id;      // Job ID
    int dead;    // Deadline of job
    int profit;  // Profit of job
};

// Comparison function to sort jobs based on profit
bool comparisonJ(Job a, Job b) {
    return a.profit > b.profit; // Sort in decreasing order of profit
}

// Function to display the activities table with wrapped columns
void displayTable(const vector<Job>& jobs, int n, int maxColumns = 6) {
    cout << "\nJob Table:\n";
    
    for (int start = 0; start < n; start += maxColumns) {
        int end = min(start + maxColumns, n); // End column for the current row set

        cout << "+-----------+";
        for (int i = start; i < end; i++) cout << "-------+";
        cout << "\n";

        cout << "| Job       |";
        for (int i = start; i < end; i++) {
            if (jobs[i].id >= 10) {  
                cout << "   " << jobs[i].id << "  |";
            } else {
                cout << "   " << jobs[i].id << "   |";
            }
        }
        cout << "\n";

        // Separator line
        cout << "+-----------+";
        for (int i = start; i < end; i++) cout << "-------+";
        cout << "\n";

        // Profit row
        cout << "| Profits   |";
        for (int i = start; i < end; i++) {
            if (jobs[i].profit >= 10) {  
                cout << "   " << jobs[i].profit << "  |";
            } else {
                cout << "   " << jobs[i].profit << "   |";
            }
        }
        cout << "\n";

        // Separator line
        cout << "+-----------+";
        for (int i = start; i < end; i++) cout << "-------+";
        cout << "\n";

        // Deadline row
        cout << "| Deadline  |";
        for (int i = start; i < end; i++) {
            if (jobs[i].dead >= 10) {  
                cout << "   " << jobs[i].dead << "  |";
            } else {
                cout << "   " << jobs[i].dead << "   |";
            }
        }
        cout << "\n";

        // Bottom border of the current section
        cout << "+-----------+";
        for (int i = start; i < end; i++) cout << "-------+";
        cout << "\n";
    }
}

void jobSequencing(vector<Job>& jobs, int n) {
    // Sort jobs in decreasing order of profit
    sort(jobs.begin(), jobs.end(), comparisonJ);

    // Array to keep track of free time slots
    vector<int> result(n, -1);
    vector<bool> slot(n, false); // To track free time slots
    int totalProfit = 0; // Variable to store the total profit

    // Iterate through all jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (note that we go backwards)
        for (int j = min(n, jobs[i].dead) - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = true; // Mark this slot as occupied
                result[j] = i;  // Store index of this job
                totalProfit += jobs[i].profit; // Add the profit of the selected job
                break;
            }
        }
    }

    // Print the sequence of jobs
    cout << "\nFollowing jobs are scheduled: " << endl;
    for (int i = 0; i < n; i++) {
        if (result[i] != -1) {
            cout << "Job " << jobs[result[i]].id << ": (Profit: " << jobs[result[i]].profit << ")" << endl;
        }
    }

    // Print the total profit from selected jobs
    cout << "\nTotal Profit from selected jobs: " << totalProfit << endl;
}


//=============== Knapsack Problem ===============
// Structure to represent an item in the knapsack
struct Item {
    int id;       
    int weight;   
    int profit;   
    double ratio; 
};

// Comparison function to sort items based on profit/weight ratio
bool comparisonK(Item a, Item b) {
    return a.ratio > b.ratio; // Sort in decreasing order of value-to-weight ratio
}

// Function to calculate the profit-to-weight ratio for each item
void calculateRatios(vector<Item>& items) {
    for (int i = 0; i < items.size(); i++) {
        items[i].ratio = (double)items[i].profit / items[i].weight; // Calculate P/W ratio
    }
}

// Function to display the items table with wrapped columns
void displayTable(const vector<Item>& items, int n, int maxColumns = 6) {
    cout << "\nItem Table:\n";
    
    for (int start = 0; start < n; start += maxColumns) {
        int end = min(start + maxColumns, n); // End column for the current row set

        cout << "+-----------+";
        for (int i = start; i < end; i++) cout << "-------+";
        cout << "\n";

        cout << "| Item      |";
        for (int i = start; i < end; i++) {
            cout << "   " << items[i].id << (items[i].id >= 10 ? "  |" : "   |");
        }
        cout << "\n";

        // Separator line
        cout << "+-----------+";
        for (int i = start; i < end; i++) cout << "-------+";
        cout << "\n";

        // Profit row
        cout << "| Profit    |";
        for (int i = start; i < end; i++) {
            cout << "   " << items[i].profit << (items[i].profit >= 10 ? "  |" : "   |");
        }
        cout << "\n";

        // Separator line
        cout << "+-----------+";
        for (int i = start; i < end; i++) cout << "-------+";
        cout << "\n";

        // Weight row
        cout << "| Weight    |";
        for (int i = start; i < end; i++) {
            cout << "   " << items[i].weight << (items[i].weight >= 10 ? "  |" : "   |");
        }
        cout << "\n";

        // Separator line
        cout << "+-----------+";
        for (int i = start; i < end; i++) cout << "-------+";
        cout << "\n";

        // P/W Ratio row
        cout << "| P/W Ratio |";
        for (int i = start; i < end; i++) {
            cout << " " << fixed << setprecision(2) << items[i].ratio  << (items[i].ratio >= 10 ? " |" : "  |");; // Display ratio with two decimal places
        }
        cout << "\n";

        // Bottom border of the current section
        cout << "+-----------+";
        for (int i = start; i < end; i++) cout << "-------+";
        cout << "\n";
    }
}

// Function to calculate maximum profit using fractional knapsack
double fractionalKnapsack(vector<Item>& items, int capacity) {
    // Sort items in decreasing order of value-to-weight ratio
    sort(items.begin(), items.end(), comparisonK);

    double totalProfit = 0.0; // Variable to store the total profit

    // Iterate through all items
    for (int i = 0; i < items.size(); i++) {
        if (capacity >= items[i].weight) {
            // If we can take the whole item
            totalProfit += items[i].profit;
            capacity -= items[i].weight; // Reduce the remaining capacity
        } else {
            // Take the fractional part of the remaining item
            totalProfit += items[i].profit * ((double)capacity / items[i].weight);
            break; // No more capacity left
        }
    }

    return totalProfit; // Return the total profit
}


//=============== Huffman Coding ===============
struct Node {
    char data;          // character
    int frequency;     // frequency of the character
    Node* left;        // left child
    Node* right;       // right child

    // Constructor
    Node(char d, int f) {
        data = d;
        frequency = f;
        left = NULL;    // Use NULL instead of nullptr
        right = NULL;   // Use NULL instead of nullptr
    }
};

// Comparator for priority queue
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->frequency > right->frequency; // min-heap
    }
};

// Function to build the Huffman tree
Node* buildHuffmanTree(const vector<pair<char, int> >& frequencies) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    // Create a leaf node for each character and add it to the priority queue
    for (size_t i = 0; i < frequencies.size(); ++i) {
        minHeap.push(new Node(frequencies[i].first, frequencies[i].second));
    }

    // Combine nodes until there's only one node left in the queue
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* internalNode = new Node('\0', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;

        minHeap.push(internalNode);
    }

    return minHeap.top(); // The root of the tree
}

// Function to generate Huffman codes
void generateHuffmanCodes(Node* root, const string& str, map<char, string>& huffmanCodes) {
    if (root == NULL) return;

    // If this node is a leaf, it contains one of the characters
    if (root->left == NULL && root->right == NULL) {
        huffmanCodes[root->data] = str;
    }

    // Traverse left
    generateHuffmanCodes(root->left, str + "0", huffmanCodes);
    // Traverse right
    generateHuffmanCodes(root->right, str + "1", huffmanCodes);
}

// Function to clean up memory
void deleteHuffmanTree(Node* root) {
    if (root == NULL) return;
    deleteHuffmanTree(root->left);
    deleteHuffmanTree(root->right);
    delete root;
}

// Function to display the current table
void displayTable(const vector<pair<char, int> >& frequencies, const map<char, string>& huffmanCodes) {
    // Output table header
    cout << "+-----------+------------+-----------+-------+-------------------+\n";
    cout << "| Character | Frequency  | Code      | Bits  | Frequency x Bits  |\n";
    cout << "+-----------+------------+-----------+-------+-------------------+\n";

	int totalFreqXBits = 0;
	int totalFreq = 0;
	
    // Output the table with characters, frequencies, codes, and calculations
    for (size_t i = 0; i < frequencies.size(); ++i) {
        char ch = frequencies[i].first;
        int freqValue = frequencies[i].second;

        // Check if the character has a code generated
        if (huffmanCodes.find(ch) != huffmanCodes.end()) {
            string code = huffmanCodes.at(ch);
            int bits = code.length();
            int freq_x_bits = freqValue * bits;
            totalFreq += freqValue;
            totalFreqXBits += freq_x_bits;

            cout << "|    " << setw(2) << ch 
                 << "     |     " << setw(2) << freqValue 
                 << "     | " << setw(10) << code 
                 << "| " << setw(4) << bits 
                 << "  |   " << setw(15) << freq_x_bits 
                 << " |\n";
        }
    	cout << "+-----------+------------+-----------+-------+-------------------+\n";
    }
    cout << "\nTotal Frequency: "<< totalFreq << endl;
    cout << "Total Freq_x_bits: "<< totalFreqXBits << endl;
}
