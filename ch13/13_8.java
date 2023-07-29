List<Integer> getRandomSubset(List<Integer> list) {
Random random = new Random();
  List<Integer>subset=list.stream().filter(
    k -> { return random.nextBoolean();
       }).collect(Collectors.toList());
  return subset;
}
class Main {
  public static void main(String[] args) {
    System.out.println("Hello world!");
  }
}
