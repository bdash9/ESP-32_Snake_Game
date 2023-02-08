void drawSnake(){
   
for(int i=0; i<indexes; i++){
//  display. fillRoundRect(index_X[i]-3,index_Y[i]-3,Grid,Grid,0,WHITE);
 tft. fillRoundRect(index_X[i]-3,index_Y[i]-3,Grid,Grid,0,ST77XX_GREEN);
}


  
}

void drawFood(){

//display. fillCircle(foodX-1,foodY-1,(Grid/2),WHITE);
 tft. fillCircle(foodX-1,foodY-1,(Grid/2),ST77XX_WHITE);
}
