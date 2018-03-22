 char read_value=0;
   int a;
    truth = true;
    for(a=0;a<numBytesToCheck;a++){
            *ramLocation_ptr=a;
            read_value=*ramLocation_ptr;
            if (read_value!=a){
               truth=false;
              }
            ramLocation_ptr++;
           }
        return truth;
  };​