int getPopulation(List<Country> countries, String continent){
  Stream<Country>sublist=countries.stream().filter(country->{return country.getContinent().equals(continent);}
  );
  stream<Integer> populations=sublist.map( c-> c.getPopulation()
  );
  int sum=0;
  for(Country c : countries){
    if(c.getContinent().equals(continent)){
      sum+=c.getPopulation();
    }
  }
  return sum;
}

class Main {
  public static void main(String[] args) {
    System.out.println("Hello world!");
  }
}
