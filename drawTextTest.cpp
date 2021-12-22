#include "pbPlots.hpp"
#include "supportLib.hpp"

using namespace std;

int main(){
    bool success;
    StringReference *errorMessage = new StringReference();
	RGBABitmapImageReference* canvasReference1 = CreateRGBABitmapImageReference();
	RGBABitmapImageReference* canvasReference2 = CreateRGBABitmapImageReference();
	RGBABitmapImageReference* canvasReference3 = CreateRGBABitmapImageReference();
	RGBABitmapImageReference* canvasReference4 = CreateRGBABitmapImageReference();
	RGBABitmapImage *combined = CreateImage(250*2, 200*2, GetWhite());
	RGBABitmapImage *image1, *image2, *image3, *image4;

	double xsa[] = {10,20,30,40,50,60,70,80,90,100};
	vector<double> xs(xsa, xsa+sizeof(xsa)/sizeof(double));

	double ysa1[] = {10,20,30,40,50,60,70,80,90,100};
	vector<double> ys1(ysa1, ysa1+sizeof(ysa1)/sizeof(double));
	double ysa2[] = {10,20,30,40,50,60,70,80,90,100};
	vector<double> ys2(ysa2, ysa2+sizeof(ysa2)/sizeof(double));
	double ysa3[] = {10,20,30,40,50,60,70,80,90,100};
	vector<double> ys3(ysa3, ysa3+sizeof(ysa3)/sizeof(double));
	double ysa4[] = {10,20,30,40,50,60,70,80,90,100};
	vector<double> ys4(ysa4, ysa4+sizeof(ysa4)/sizeof(double));
	

success = DrawScatterPlot(canvasReference1, 250, 200, &xs, &ys1,errorMessage);
success = success && DrawScatterPlot(canvasReference2, 250, 200, &xs, &ys2,errorMessage);
success = success && DrawScatterPlot(canvasReference3, 250, 200, &xs, &ys3,errorMessage);
success = success && DrawScatterPlot(canvasReference4, 250, 200, &xs, &ys4,errorMessage);

if(success){
  image1 = canvasReference1->image;
  image2 = canvasReference2->image;
  image3 = canvasReference3->image;
  image4 = canvasReference4->image;

  DrawImageOnImage(combined, image1, 0, 0);
  DrawImageOnImage(combined, image2, 0, 200);
  DrawImageOnImage(combined, image3, 250, 0);
  DrawImageOnImage(combined, image4, 250, 200);
}

	

    if(success){
        vector<double> *pngdata = ConvertToPNG(combined);
        WriteToFile(pngdata, "example2.png");
        DeleteImage(combined);
	}else{
        cerr << "Error: ";
        for(wchar_t c : *errorMessage->string){
            wcerr << (char)c;
        }
        cerr << endl;
	}

	return success ? 0 : 1;
}