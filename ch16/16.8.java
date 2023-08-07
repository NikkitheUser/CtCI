class Main {
  String ones[] = {"Zero", "one", "two", "three", "four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
  String tens[]={"twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
  string huge[]={"", "thousand", "million"};
  string hundred[]={"hundred"};
String convert(int num){
  if(num==0){
    return ones[0];
  }
  return "negative" + convert(-1 * num);
}
LinkedList<String> parts=new LinkedList<String>();
int chunkCount=0;

while(num >0){
  if(num% 1000!=0){
    String chunk= convertChunk(num%1000)+" "+ huge[chunkContent];
    parts.addFirst(chunk);
  }
  num/=1000;
  chunkCount++;
}
  return listToString(parts);
}
String convertChunk(int number){
  LinkedList<String> parts=new linkedList<String>();
  if(number>=100){
    parts.addLast(ones[number/100]);
    parts.addLast(hundred);
    number%=100;
  }
  if (number>=10 && number<=19){
    parts.addLast(ones[number]);
  }
  else if(number >= 20){
    parts.addLast(tens[number /10]);
    number%=100;
  }
  if (number>=1 && number<=9){
    parts.addLast(ones[number]);
  }
  return listToString(parts);
}
String listToString(LinkedList<String> parts){
  StringBuilder sb= new StringBuilder();
  while(parts.size() >1){
    sb.append(parts.pop());
    return sb.toString();
  }
}
  public static void main(String[] args) {
  System.out.println("give me a number to change into a full string!");
Scanner sc = new Scanner(System.in);
int num = sc.nextInt();

  System.out.println(convert(num));
                    
  }
}
