{
//=========Macro generated from canvas: c1/c1
//=========  (Mon Dec  3 13:29:11 2018) by ROOT version5.34/36
   TCanvas *c1 = new TCanvas("c1", "c1",10,45,700,502);
   gStyle->SetOptTitle(0);
   c1->Range(-601.478,-0.6961829,5701.615,4.172899);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetLeftMargin(0.1174785);
   c1->SetBottomMargin(0.1431579);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TF1 *KinemFunc = new TF1("KinemFunc","((x/139.4)-sqrt((x^2/139.4^2)-1))*26.033",139,10000);
   KinemFunc->SetFillColor(19);
   KinemFunc->SetFillStyle(0);
   KinemFunc->SetLineColor(4);
   KinemFunc->SetLineWidth(3);
   KinemFunc->GetXaxis()->SetTitle("Energy (MeV)");
   KinemFunc->GetXaxis()->SetRange(1,50);
   KinemFunc->GetXaxis()->CenterTitle(true);
   KinemFunc->GetXaxis()->SetNdivisions(409);
   KinemFunc->GetXaxis()->SetLabelFont(42);
   KinemFunc->GetXaxis()->SetLabelSize(0.05);
   KinemFunc->GetXaxis()->SetTitleSize(0.05);
   KinemFunc->GetXaxis()->SetTitleOffset(1.32);
   KinemFunc->GetXaxis()->SetTitleFont(42);
   KinemFunc->GetYaxis()->SetTitle("arrival time difference (nsec)");
   KinemFunc->GetYaxis()->CenterTitle(true);
   KinemFunc->GetYaxis()->SetLabelFont(42);
   KinemFunc->GetYaxis()->SetLabelSize(0.05);
   KinemFunc->GetYaxis()->SetTitleSize(0.05);
   KinemFunc->GetYaxis()->SetTitleFont(42);
   KinemFunc->Draw("");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
