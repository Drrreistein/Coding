string str;
   int count[256]={0};
   
   while(getline(cin, str)){
       int max=0;
       for(int i=0; i<str.length(); i++){
           count[str.at(i)]++;
           if(count[str.at(i)]>max){
               max = count[str.at(i)];
           }
       }
       while(max){
            for(int i=0; i<256; i++){
                if(count[i]==max)
                printf("%c",i);
            }
            max--;
       }
       printf("\n");
       
   }