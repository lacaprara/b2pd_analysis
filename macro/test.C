void test() {
  vector<int> pippo(2);
  pippo[0]=1;
  pippo[1]=10;
  for (vector<int>::const_iterator p=pippo.begin(); p!=pippo.end(); ++p) {
    cout << "p " << *p << endl;
  }
}
