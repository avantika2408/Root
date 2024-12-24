#include <TCanvas.h>
#include <TH1F.h>
#include <iostream>
#include <fstream>
#include <TGraph.h>
using namespace std;

int main(){
    
    TGraph * graph = new TGraph();
    graph -> SetMarkerStyle(kFullCircle);
    fstream file;
    file.open("data2.txt", ios::in);

    double x, y;

    while (file >> x >> y) {
        graph -> SetPoint(graph->GetN(), x, y);
    }
    file.close();
    
    TCanvas * canvas = new TCanvas();
    graph->Draw("ALP");
    
    return 0;
}
