#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <algorithm>
// Class to process data concurrently
class DataProcessor {
private:
    std::vector<std::string> dataset;
    std::vector<std::string> processedData;
    std::mutex mutex;
    void processChunk(int startIndex, int chunkSize) {
        //mutex.lock();
        for (int i = startIndex; i < startIndex + chunkSize; ++i)
        {
            std::cout << i << std::endl;
            reverse(dataset[i].begin(), dataset[i].end());
            processedData[i] = dataset[i];
        }
        //mutex.unlock();
        return;
    }
public:
    DataProcessor() {}

    // Function to load data from file
    bool loadData(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                dataset.push_back(line);
            }
            file.close();
            return true;
        }
        return false;
    }

    void processInParallel(int numThreads) {
        std::vector<std::thread> threads;
        processedData = std::vector<std::string>(dataset.size());
        if (dataset.size() % numThreads != 0) {
            std::cout << "Process not possible, cannot equally partition dataset" << std::endl;
            return;
        }
        else
        {
            int partition = dataset.size() / numThreads;
            int counter = 0;
            int currentSection = partition;
            std::cout << currentSection << std::endl;
            while (counter <= currentSection)
            {
                if (currentSection > dataset.size()) break;
                counter++;
                if (counter == currentSection - 1)
                {
                    int temp = currentSection - partition;
                    threads.push_back(std::thread(&DataProcessor::processChunk, this, temp, partition)); //when using threads in a class and using class methods, the reference must point to the instance of the object using this
                    std::cout << "Temp: " << temp << "; Partition: " << partition << std::endl;
                    currentSection += partition;
                    std::cout << "currentSection: " << currentSection << "; Partition: " << partition << std::endl;
                }
            }
            std::cout << "Joiming" << std::endl;
            threads[0].join();
            threads[1].join();
            threads[2].join();
            threads[3].join();
            std::cout << "joined" << std::endl;
            /*
            for (auto& thread : threads)
            {
                thread.join();
                std::cout << "Thread joined" << std::endl;
            }
            */
        }
    }




    // Function to save the processed data to file
    bool saveData(const std::string& filename) {
        std::cout << "Running saveData" << std::endl;
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const std::string& line : processedData) {
                std::cout << "line " << line << " added" << std::endl;
                file << line << "\n";
            }
            file.close();
            std::cout << "All done" << std::endl;
            return true;
        }
        return false;
    }
};

int main(int argc, char** argv) {
    if (argc < 4) {
        std::cout << "Usage: ./data_processing_program <input_file> <output_file> <num_threads>" << std::endl;
        return 0;
    }
    std::string inputFilename = argv[1];
    std::string outputFilename = argv[2];
    int numThreads = std::stoi(argv[3]);

    DataProcessor dataProcessor;

    // Load data from file
    bool loadSuccess = dataProcessor.loadData(inputFilename);
    if (!loadSuccess) {
        std::cout << "Error: Failed to load data from file." << std::endl;
        return 0;
    }

    // Process data in parallel
    dataProcessor.processInParallel(numThreads);
    std::cout << "Data processed" << std::endl;
    // Save processed data to file
    bool saveSuccess = dataProcessor.saveData(outputFilename);
    if (saveSuccess) {
        std::cout << "Data processing completed successfully. Processed data saved to " << outputFilename << "." << std::endl;
    }
    else {
        std::cout << "Error: Failed to save processed data to file." << std::endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
