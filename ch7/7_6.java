
public enum Orientation(){
  LEFT, TOP, RIGHT, BOTTOM;
}
public Orrientation getOpposite(){
  switch (this){
      case:INNER: return OUTER;
    case OUTER: return INNER;
  }
}
class Main {
  public static void main(String[] args) {
    System.out.println("Hello world!");
  }
}
