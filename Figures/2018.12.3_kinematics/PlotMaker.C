{
  TF1* KinemFunc = new TF1("KinemFunc","((x/139.4)-sqrt((x^2/139.4^2)-1))*26.033",139.,10000.);
  KinemFunc->Draw();


}
