void plotPdfResults() {

  //const char* what="_iptubeK0";
  int ch=1;
  const char* what="_iptubeK0";
  TString inFile=Form("results/EtaPK0_ch%d%s.mlFitter_Config.pdfPlot.PdfAct.root",ch,what);

  TFile *inF = new TFile(inFile);
  inF->cd();

  RooPlot* Mbc_the_MbcR=(RooPlot*)inF->Get("Mbc_the_MbcR");
  Mbc_the_MbcR->Draw();
  gPad->Print(Form("Mbc_the_MbcR_ch%d%s.pdf",ch,what));

  RooPlot* DeltaE_the_DeltaER=(RooPlot*)inF->Get("DeltaE_the_DeltaER");
  DeltaE_the_DeltaER->Draw();
  gPad->Print(Form("DeltaE_the_DeltaER_ch%d%s.pdf",ch,what));


  RooPlot* DeltaT_the_dtSig=(RooPlot*)inF->Get("DeltaT_the_dtSig");
  DeltaT_the_dtSig->Draw();
  gPad->Print(Form("DeltaT_the_dtSig_ch%d%s.pdf",ch,what));

  RooPlot* Mbc_the_MbcX=(RooPlot*)inF->Get("Mbc_the_MbcX");
  Mbc_the_MbcX->Draw();
  gPad->Print(Form("Mbc_the_MbcX_ch%d%s.pdf",ch,what));

  RooPlot* DeltaE_the_DeltaEX=(RooPlot*)inF->Get("DeltaE_the_DeltaEX");
  DeltaE_the_DeltaEX->Draw();
  gPad->Print(Form("DeltaE_the_DeltaEX_ch%d%s.pdf",ch,what));


  RooPlot* Mbc_the_MbcBkg=(RooPlot*)inF->Get("Mbc_the_MbcBkg");
  Mbc_the_MbcBkg->Draw();
  gPad->Print(Form("Mbc_the_MbcBkg_ch%d%s.pdf",ch,what));

  RooPlot* DeltaE_the_DeltaEBkg=(RooPlot*)inF->Get("DeltaE_the_DeltaEBkg");
  DeltaE_the_DeltaEBkg->Draw();
  gPad->Print(Form("DeltaE_the_DeltaEBkg_ch%d%s.pdf",ch,what));


  RooPlot* DeltaT_the_dtBkg=(RooPlot*)inF->Get("DeltaT_the_dtBkg");
  DeltaT_the_dtBkg->Draw();
  gPad->Print(Form("DeltaT_the_dtBkg_ch%d%s.pdf",ch,what));

  RooPlot* Mbc_the_MbcBB=(RooPlot*)inF->Get("Mbc_the_MbcBB");
  Mbc_the_MbcBB->Draw();
  gPad->Print(Form("Mbc_the_MbcBB_ch%d%s.pdf",ch,what));

  RooPlot* DeltaE_the_DeltaEBB=(RooPlot*)inF->Get("DeltaE_the_DeltaEBB");
  DeltaE_the_DeltaEBB->Draw();
  gPad->Print(Form("DeltaE_the_DeltaEBB_ch%d%s.pdf",ch,what));


  RooPlot* DeltaT_the_dtBB=(RooPlot*)inF->Get("DeltaT_the_dtBB");
  DeltaT_the_dtBB->Draw();
  gPad->Print(Form("DeltaT_the_dtBB_ch%d%s.pdf",ch,what));

  // RooPlot* MetaP_the_MetaPR=(RooPlot*)inF->Get("MetaP_the_MetaPR");
  // MetaP_the_MetaPR->Draw();
  // gPad->Print(Form("MetaP_the_MetaPR%s.pdf",ch,what));
  // RooPlot* MetaP_the_MetaPX=(RooPlot*)inF->Get("MetaP_the_MetaPX");
  // MetaP_the_MetaPX->Draw();
  // gPad->Print(Form("MetaP_the_MetaPX%s.pdf",ch,what));
  // RooPlot* MetaP_the_MetaPBkg=(RooPlot*)inF->Get("MetaP_the_MetaPBkg");
  // MetaP_the_MetaPBkg->Draw();
  // gPad->Print(Form("MetaP_the_MetaPBkg%s.pdf",ch,what));
  // RooPlot* MetaP_the_MetaPBB=(RooPlot*)inF->Get("MetaP_the_MetaPBB");
  // MetaP_the_MetaPBB->Draw();
  // gPad->Print(Form("MetaP_the_MetaPBB%s.pdf",ch,what));
  //
  // RooPlot* MetaP_the_MetaPR=(RooPlot*)inF->Get("MetaP_the_MetaPR");
  // MetaP_the_MetaPR->Draw();
  // gPad->Print(Form("MetaP_the_MetaPR%s.pdf",ch,what));
  // RooPlot* MetaP_the_MetaPX=(RooPlot*)inF->Get("MetaP_the_MetaPX");
  // MetaP_the_MetaPX->Draw();
  // gPad->Print(Form("MetaP_the_MetaPX%s.pdf",ch,what));
  // RooPlot* MetaP_the_MetaPBkg=(RooPlot*)inF->Get("MetaP_the_MetaPBkg");
  // MetaP_the_MetaPBkg->Draw();
  // gPad->Print(Form("MetaP_the_MetaPBkg%s.pdf",ch,what));
  // RooPlot* MetaP_the_MetaPBB=(RooPlot*)inF->Get("MetaP_the_MetaPBB");
  // MetaP_the_MetaPBB->Draw();
  // gPad->Print(Form("MetaP_the_MetaPBB%s.pdf",ch,what));
}
