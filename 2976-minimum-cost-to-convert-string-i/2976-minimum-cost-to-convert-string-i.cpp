class Solution {
public:
    // Function to calculate the minimum cost of transforming source to target
    long long minimumCost(string source, string target, vector<char>& originalChars, vector<char>& changedChars, vector<int>& transformationCosts) {
        // Number of distinct characters
        int numCharacters = 26;

        // Matrix to store the minimum cost between characters
        vector<vector<long long>> distanceMatrix(numCharacters, vector<long long>(numCharacters, INT_MAX));

        // Initialize the diagonal of the matrix to 0
        for (int i = 0; i < numCharacters; i++)
            distanceMatrix[i][i] = 0;

        // Fill the matrix with the minimum transformation costs
        for (int i = 0; i < originalChars.size(); i++) {
            int sourceChar = originalChars[i] - 'a';
            int targetChar = changedChars[i] - 'a';
            long long weight = transformationCosts[i];

            distanceMatrix[sourceChar][targetChar] = min(distanceMatrix[sourceChar][targetChar], weight);
        }

        // Apply Floyd-Warshall algorithm to find the minimum costs between all pairs of characters
        for (int k = 0; k < numCharacters; k++) {
            for (int i = 0; i < numCharacters; i++) {
                for (int j = 0; j < numCharacters; j++) {
                    distanceMatrix[i][j] = min(distanceMatrix[i][j], (distanceMatrix[i][k] + distanceMatrix[k][j]));
                }
            }
        }

        // Calculate the total cost of transforming source to target
        long long totalCost = 0;
        for (int i = 0; i < source.length(); i++) {
            int sourceChar = source[i] - 'a';
            int targetChar = target[i] - 'a';

            // Skip if source and target characters are the same
            if (sourceChar == targetChar) continue;

            // Check if a valid transformation exists
            if (distanceMatrix[sourceChar][targetChar] == INT_MAX) return -1;
            else
                // Accumulate the cost
                totalCost += (long long)distanceMatrix[sourceChar][targetChar];
        }

        return totalCost;
    }
};
