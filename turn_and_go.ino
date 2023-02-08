void Clockwise(){
if(index_X[0]==index_X[1]){
 // if(index_Y[0]<index_Y[1]){
    nextX=index_X[0]+Grid;
    nextY=index_Y[0];
 // }
 // else{
  ////  nextX=index_X[0]+Grid;
  //  nextY=index_Y[0];
 // }
}
else if(index_Y[0]==index_Y[1]){
  
  if(HeadX<index_X[1]){
    nextY=index_Y[0]-Grid;
    nextX=index_X[0];
  }
  else{
  //  Serial.println("J");
    nextY=index_Y[0]+Grid;
    nextX=index_X[0];
  }
}
  
}

void antiClockwise(){
if(index_X[0]==index_X[1]){
  //if(index_Y[0]<index_Y[1]){
    nextX=index_X[0]-Grid;
    nextY=index_Y[0];
//  }
//  else{
  //  nextX=index_X[0]+Grid;
 //   nextY=index_Y[0];
 // }
}
else if(index_Y[0]==index_Y[1]){
  if(HeadX<index_X[1]){
    nextY=index_Y[0]+Grid;
    nextX=index_X[0];
  }
  else{
    nextY=index_Y[0]-Grid;
    nextX=index_X[0];
  }
}
  
}

void Go(){

if(index_X[0]==index_X[1]){
  if(HeadY<index_Y[1]){
    nextX=index_X[0];
    nextY=index_Y[0]-Grid;
  }
  else{
    nextX=index_X[0];
    nextY=index_Y[0]+Grid;
  }
}
else if(index_Y[0]==index_Y[1]){
  if(HeadX<index_X[1]){
    nextY=index_Y[0];
    nextX=index_X[0]-Grid;
  }
  else{
    nextY=index_Y[0];
    nextX=index_X[0]+Grid;
  }
}

  
}

void limit(){
/*
if(index_Y[0]>64){
  
  index_Y[0]=20;
}
else if(index_Y[0]<20){
  index_Y[0]=60;
}
*/

// 135 Height of screen
if(index_Y[0]>130){
  
  index_Y[0]=25;
}

else if(index_Y[0]<20){
  index_Y[0]=126;
}
/*
if(index_X[0]>128){
  index_X[0]=5;
}
else if(index_X[0]<5){
  index_X[0]=125;
}
*/
//240 width of screen for snake
if(index_X[0]>235){
  index_X[0]=5;
}

else if(index_X[0]<5){
  index_X[0]=232;
}
  
}
