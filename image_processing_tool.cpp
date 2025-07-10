#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void showMenu() {
    cout << "\n=== IMAGE PROCESSING TOOL ===\n";
    cout << "1. Apply Grayscale\n";
    cout << "2. Apply Blur\n";
    cout << "3. Apply Sharpen\n";
    cout << "4. Adjust Brightness and Contrast\n";
    cout << "5. Crop Image\n";
    cout << "6. Resize Image\n";
    cout << "7. Save Image\n";
    cout << "8. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    string path;
    cout << "📁 Enter image path: ";
    getline(cin, path);

    Mat image = imread(path);
    if (image.empty()) {
        cout << "❌ Could not load image.\n";
        return 1;
    }

    Mat edited = image.clone();
    imshow("🖼 Original Image", image);
    waitKey(0);
    destroyAllWindows();

    int choice;
    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            cvtColor(edited, edited, COLOR_BGR2GRAY);
            imshow("Grayscale", edited);
            waitKey(0);
        }
        else if (choice == 2) {
            int ksize;
            cout << "Enter blur kernel size (odd number): ";
            cin >> ksize;
            blur(edited, edited, Size(ksize, ksize));
            imshow("Blurred", edited);
            waitKey(0);
        }
        else if (choice == 3) {
            Mat kernel = (Mat_<float>(3,3) <<
                0, -1, 0,
               -1, 5, -1,
                0, -1, 0);
            filter2D(edited, edited, -1, kernel);
            imshow("Sharpened", edited);
            waitKey(0);
        }
        else if (choice == 4) {
            double alpha; int beta;
            cout << "Enter contrast (alpha, e.g. 1.5): ";
            cin >> alpha;
            cout << "Enter brightness (beta, e.g. 50): ";
            cin >> beta;
            edited.convertTo(edited, -1, alpha, beta);
            imshow("Adjusted", edited);
            waitKey(0);
        }
        else if (choice == 5) {
            int x, y, w, h;
            cout << "Enter x y width height: ";
            cin >> x >> y >> w >> h;
            Rect roi(x, y, w, h);
            if (x+w <= edited.cols && y+h <= edited.rows) {
                edited = edited(roi);
                imshow("Cropped", edited);
                waitKey(0);
            } else {
                cout << "❌ Invalid crop dimensions.\n";
            }
        }
        else if (choice == 6) {
            int width, height;
            cout << "Enter new width and height: ";
            cin >> width >> height;
            resize(edited, edited, Size(width, height));
            imshow("Resized", edited);
            waitKey(0);
        }
        else if (choice == 7) {
            string savePath;
            cout << "Enter filename to save (e.g. output.jpg): ";
            cin >> savePath;
            imwrite(savePath, edited);
            cout << "✅ Image saved as " << savePath << "\n";
        }
        else if (choice == 8) {
            cout << "👋 Exiting.\n";
            break;
        }
        else {
            cout << "❌ Invalid option.\n";
        }
    }

    return 0;
}