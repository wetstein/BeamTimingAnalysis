{
  TF1* KinemFunc = new TF1("KinemFunc","((x/0.1394)-sqrt((x^2/0.1394^2)-1))*26.033",139.,10000.);
  KinemFunc->Draw();


}
