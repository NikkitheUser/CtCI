class Chopsticks {
  private Lock lock;
public Chopsticks(){
  lock = new ReentrantLock();
}
  public void pickup(){
    lock.lock();
  }
  public void putdown(){
    lock.unlock();
  }
  public boolean pickup(){
    return lock.trylock();
  }
}
class Philosophers extends Thread{
  private int bites=10;
  private Chopsticks left, right;
  public Philosophers(Chopsticks left, Chopsticks right){
    this.left=left;
    this.right=right;
  }
  public void eat(){
    if(pickup()){
        munch();
    putdown();
    }
  
  }
  public void pickup(){
    left.pickup();
    right.pickup();
  }
  public void munch(){
    
  }

  public void putdown(){
    right.putdown();
    left.putdown();
  }
  public void run(){
    for(int i=0;i<bites;i++){
      eat();
    }
  }
  public boolean pickup(){
    if(!left.pickup()){
      return false;
    }
    if(!right.pickup()){
      return false;
    }
  }
}

class Main {
  public static void main(String[] args) {
    System.out.println("Hello world!");
  }
}
