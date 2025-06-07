#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main() {
    std::string folderPath = "E:\\RDR 2 Gameplay"; // 🔁 CHANGE THIS

    try {
        for (const auto& entry : fs::directory_iterator(folderPath)) {
            if (fs::is_regular_file(entry.status())) {
                fs::path filePath = entry.path();
                std::string extension = filePath.extension().string(); // e.g., ".mp4", ".prproj"

                // Remove dot from extension (".mp4" → "mp4")
                if (!extension.empty() && extension[0] == '.') {
                    extension.erase(0, 1);
                }

                // Handle files with no extension
                if (extension.empty()) {
                    extension = "no_extension";
                }

                // Create destination folder path
                fs::path targetDir = folderPath + "/" + extension + "_files";

                // Create the folder if it doesn't exist
                if (!fs::exists(targetDir)) {
                    fs::create_directory(targetDir);
                }

                // Move the file
                fs::path newLocation = targetDir / filePath.filename();
                fs::rename(filePath, newLocation);

                std::cout << "Moved: " << filePath.filename() << " → " << targetDir << std::endl;
            }
        }

        std::cout << "\n✅ All files organized by extension.\n";
    } catch (const fs::filesystem_error& e) {
        std::cerr << "❌ Filesystem error: " << e.what() << std::endl;
    }

    return 0;
}
