#include <sstream>
#include "pbPlots.hpp"
#include "supportLib.hpp"

using namespace std;

int main(int argc, char* argv[]){
	double myHeight[88];
	std::stringstream convert[88];
	for(int i=0;i<88;i++){
		convert[i] << argv[i+1];
		if (!(convert[i] >> myHeight[i]))
			myHeight[i]=0;
	}
	
 
	

    bool success1;
    bool success2;

    StringReference *errorMessage = new StringReference();
	RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();

	double xsa[] = {10,20,30,40,50,60,70,80,90,100,110};
	vector<double> xs(xsa, xsa+sizeof(xsa)/sizeof(double));
	// double ysa[] = {10,20,30,40,50,60,70,80,90,100};
	double ysa[] = {myHeight[0], myHeight[1], myHeight[2], myHeight[3], myHeight[4], myHeight[5], myHeight[6], myHeight[7], myHeight[8], myHeight[9], myHeight[10]};
	vector<double> ys1(ysa, ysa+sizeof(ysa)/sizeof(double));
	
	ScatterPlotSeries *series1 = GetDefaultScatterPlotSeriesSettings();	//ADD registers
	series1->xs = &xs;
	series1->ys = &ys1;
	series1->linearInterpolation = true;
	series1->lineType = toVector(L"solid");
	series1->lineThickness = 3.0;
	series1->color = CreateRGBColor(255.0/256.0, 255.0/256.0, 0.0/256.0);	//Yellow

	double ysb[] = {myHeight[11], myHeight[12], myHeight[13], myHeight[14], myHeight[15], myHeight[16], myHeight[17], myHeight[18], myHeight[19], myHeight[20],myHeight[21]};
	vector<double> ys2(ysb, ysb+sizeof(ysb)/sizeof(double));
	
	ScatterPlotSeries *series2 = GetDefaultScatterPlotSeriesSettings();	//SUB registers
	series2->xs = &xs;
	series2->ys = &ys2;
	series2->linearInterpolation = true;
	series2->lineType = toVector(L"solid");
	series2->lineThickness = 3.0;
	series2->color = CreateRGBColor(51.0/256.0, 153.0/256.0, 51.0/256.0);	//Green

	double ysc[] = {myHeight[22], myHeight[23], myHeight[24], myHeight[25], myHeight[26], myHeight[27], myHeight[28], myHeight[29], myHeight[30],myHeight[31],myHeight[32]};
	vector<double> ys3(ysc, ysc+sizeof(ysc)/sizeof(double));
	
	ScatterPlotSeries *series3 = GetDefaultScatterPlotSeriesSettings();	//MUL registers
	series3->xs = &xs;
	series3->ys = &ys3;
	series3->linearInterpolation = true;
	series3->lineType = toVector(L"solid");
	series3->lineThickness = 3.0;
	series3->color = CreateRGBColor(255.0/256.0, 0.0/256.0, 0.0/256.0);	//Red

	double ysd[] = {myHeight[33], myHeight[34], myHeight[35], myHeight[36], myHeight[37], myHeight[38], myHeight[39], myHeight[40], myHeight[41], myHeight[42], myHeight[43]};
	vector<double> ys4(ysd, ysd+sizeof(ysd)/sizeof(double));
	
	ScatterPlotSeries *series4 = GetDefaultScatterPlotSeriesSettings();	//DEV registers
	series4->xs = &xs;
	series4->ys = &ys4;
	series4->linearInterpolation = true;
	series4->lineType = toVector(L"solid");
	series4->lineThickness = 3.0;
	series4->color = CreateRGBColor(0.0/256.0, 0.0/256.0, 204.0/256.0); //Blue


	double yse[] = {myHeight[44], myHeight[45], myHeight[46], myHeight[47], myHeight[48], myHeight[49], myHeight[50], myHeight[51], myHeight[52], myHeight[53], myHeight[54]};
	vector<double> ys5(yse, yse+sizeof(yse)/sizeof(double));
	
	ScatterPlotSeries *series5 = GetDefaultScatterPlotSeriesSettings();	//ADD memory
	series5->xs = &xs;
	series5->ys = &ys5;
	series5->linearInterpolation = true;
	series5->lineType = toVector(L"dashed");
	series5->lineThickness = 3.0;
	series5->color = CreateRGBColor(255.0/256.0, 255.0/256.0, 0.0/256.0);	//Yellow

	double ysf[] = {myHeight[55], myHeight[56], myHeight[57], myHeight[58], myHeight[59], myHeight[60], myHeight[61], myHeight[62], myHeight[63], myHeight[64], myHeight[65]};
	vector<double> ys6(ysf, ysf+sizeof(ysf)/sizeof(double));
	
	ScatterPlotSeries *series6 = GetDefaultScatterPlotSeriesSettings();	//SUB memory
	series6->xs = &xs;
	series6->ys = &ys6;
	series6->linearInterpolation = true;
	series6->lineType = toVector(L"dashed");
	series6->lineThickness = 3.0;
	series6->color = CreateRGBColor(51.0/256.0, 153.0/256.0, 51.0/256.0);	//Green

	double ysg[] = {myHeight[66], myHeight[67], myHeight[68], myHeight[69], myHeight[70], myHeight[71], myHeight[72], myHeight[73], myHeight[74],myHeight[75],myHeight[76]};
	vector<double> ys7(ysg, ysg+sizeof(ysc)/sizeof(double));
	
	ScatterPlotSeries *series7 = GetDefaultScatterPlotSeriesSettings();	//MUL memory
	series7->xs = &xs;
	series7->ys = &ys7;
	series7->linearInterpolation = true;
	series7->lineType = toVector(L"dashed");
	series7->lineThickness = 3.0;
	series7->color = CreateRGBColor(255.0/256.0, 0.0/256.0, 0.0/256.0);	//Red

	double ysh[] = {myHeight[77], myHeight[78], myHeight[79], myHeight[80], myHeight[81], myHeight[82], myHeight[83], myHeight[84], myHeight[85], myHeight[86], myHeight[87]};
	vector<double> ys8(ysh, ysh+sizeof(ysh)/sizeof(double));
	
	ScatterPlotSeries *series8 = GetDefaultScatterPlotSeriesSettings();	//DEV memory
	series8->xs = &xs;
	series8->ys = &ys8;
	series8->linearInterpolation = true;
	series8->lineType = toVector(L"dashed");
	series8->lineThickness = 3.0;
	series8->color = CreateRGBColor(0.0/256.0, 0.0/256.0, 204.0/256.0); //Blue

	ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
	settings->width = 1920;
	settings->height = 1080;
	settings->title = toVector(L"Yellow - SUM; Green - SUBTRACTION; Red - MULTIPLICATION; Blue - DEVISION;        SOLID - REGISTERS; DASHED - MEMORY;");
	settings->xLabel = toVector(L"                        SHORT       UNSIGNED SHORT         INT          UNSIGNED INT      LONG     UNSIGNED LONG       LONG LONG    UNS LONG LONG     FLOAT          DOUBLE       LONG DOUBLE                   ");
	// settings->xLabel = toVector(L"OPERATIONS");
	settings->yLabel = toVector(L"TIME, 10*10^-9 seconds (nanoseconds)");
	settings->autoBoundaries = true;
	settings->yMin=50.0;
	settings->yMax=250.0;
	settings->xMin=10.0;
	settings->xMax=100.0;
	settings->autoPadding = true;
  	//DrawText(imageReference->image, 100, 100, toVector(L"aaaaaaaaaaaaaaaaaaaa"), GetBlack());
	settings->scatterPlotSeries->push_back(series1);
	settings->scatterPlotSeries->push_back(series2);
	settings->scatterPlotSeries->push_back(series3);
	settings->scatterPlotSeries->push_back(series4);
	
		
	success1 = DrawScatterPlotFromSettings(imageReference, settings, errorMessage);

	if(success1){
        vector<double> *pngdata = ConvertToPNG(imageReference->image);
        WriteToFile(pngdata, "System_Performance1.png");
        DeleteImage(imageReference->image);
	}else{
	    cerr << "Error: ";
        for(wchar_t c : *errorMessage->string){
            cerr << (char)c;
        }
        cerr << endl;
	}

	settings->scatterPlotSeries->pop_back();
	settings->scatterPlotSeries->pop_back();
	settings->scatterPlotSeries->pop_back();
	settings->scatterPlotSeries->pop_back();

	settings->scatterPlotSeries->push_back(series5);
	settings->scatterPlotSeries->push_back(series6);
	settings->scatterPlotSeries->push_back(series7);
	settings->scatterPlotSeries->push_back(series8);

	success2 = DrawScatterPlotFromSettings(imageReference, settings, errorMessage);

	if(success2){
	        vector<double> *pngdata = ConvertToPNG(imageReference->image);
	        WriteToFile(pngdata, "System_Performance2.png");
	        DeleteImage(imageReference->image);
		}else{
		    cerr << "Error: ";
	        for(wchar_t c : *errorMessage->string){
	            cerr << (char)c;
	        }
	        cerr << endl;
		}

	
	return (success1 && success2) ? 0 : 1;
}