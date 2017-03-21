#include <opencv2/opencv.hpp>
#include <iostream>

int main ( int argc, char *argv[] ){
	
	//Ensure we have srguments
	if( argc != 2 ) {
		std::cout << "Proper usage is " << argv[0] << " <filename>\r\n";
	}

	cv::Mat inputImage, outputImage;

	inputImage = cv::imread( argv[1] );
	outputImage = inputImage;

	for( int col = 0; col < inputImage.cols; col++) {
		for( int row = 0; row < inputImage.rows; row++) {
			cv::Vec3b bgrPixel = inputImage.at<cv::Vec3b>( row, col );
			if( ( ( ( bgrPixel[0] + bgrPixel[1] ) * 2) >= bgrPixel[2] ) && ( (bgrPixel[0] < 200) || (bgrPixel[1] < 200) || (bgrPixel[2] < 200) ) ){
				bgrPixel[2] = 0;
				bgrPixel[1] = 0;
				bgrPixel[0] = 0;
				outputImage.at<cv::Vec3b>(row, col) = bgrPixel;
			}
		}
	
	}
	
	std::string outName = argv[1];
	outName += ".filtered.tif";
	imwrite( outName, outputImage );
}
