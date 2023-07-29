class Locker{
  private static Locker instance;
  private int numberOfLocks =5;
  private LockNode[] locks;
  private HashMap<Integer, LinkedList<LockNode>> LockOrder;
  private Locker(int count){}
  private static Locker getInstance(){return instance;}
  public static synchronized Locker initialize (int count){
    if(instance==null) instance = new Locker(count);
    return instance;
  }
  public boolean hasCycle(HashmMap<Integer, Boolean> touchedNodes,int[] resourcesInOrder){
    for (int resources : resourcesInOrder){
      if(touchedNodes.get(resource)==false){
        LockNode n = locks[resources];
        if(n.hasCycle(touchedNodes)){
          return true;
        }
      }
    }
    return false;
  }
}
class Main {
  public static void main(String[] args) {
    System.out.println("Hello world!");
  }
}
