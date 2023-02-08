void Location(){
  while(true){
    //foodX=random(5,125);
    //foodY=random(20,60);
    foodX=random(5,235);
    foodY=random(25,130);
    if(foodX%(Grid)==0 &&foodY%(Grid)==0){
      choose=true;
    for(int i=0;i<indexes;i++){
      if(foodX==index_X[i] &&foodY==index_Y[i]){
        choose=false;
        break;
      }}
      if (choose==true){
        break;
      }}
}
}

void Eat(){
if(foodX== nextX && foodY== nextY){
  indexes++;
  Location();
  Score+=100;
  eatSound();}
//  for(int x=indexes-2; x>=0; x--){
//   index_X[x+1]=index_X[x];
//   
//}
//
//for(int y=indexes-2; y>=0; y--){
//   index_Y[y+1]=index_Y[y];
//   
//}
// index_X[0]=nextX;
// index_Y[0]=nextY;
  
}

  
