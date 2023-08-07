class Main {
  HashSet<Integer> allLengths(int k, int shorter, int longer){
    HashSet<Integer> lengths = new Hashset<Integer>();
    for(int nShorter =0; nShorter <=k; nShorter++){
      int nLonger= k- nShorter;
      int length= nShorter *shorter+nLonger *longer;
      lengths.add(length);
    
    }
    return lengths;
  }
  public static void main(String[] args) {
    System.out.println("Hello world!");
  }
}
