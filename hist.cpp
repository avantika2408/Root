#include <TCanvas.h>
#include <TH1F.h>

int test(){
    TCanvas c("c", "Simple Canvas", 800, 600);
    TH1F h("h", "Histogram", 100, 0, 100);
    h.Fill(10);
    h.Fill(90);
    h.GetXaxis()->SetTitle("X");
    h.Draw();
    c.SaveAs("hist.png");
    return 0;
}

