#include<reg51.h>
char data *p=0x30;
char data *q=0x30;
char data *r=0x40;
int a,b,c,d,e,f,g,h,i,j;
sbit up=P1^0;			////  keyboard initialization/////
sbit dn=P1^1;
sbit ch=P1^2;
sbit no=P1^3;
sbit sp=P1^4;
sbit ok=P1^5;
sbit cl=P1^6;
sbit tx=P1^7;
sbit rs=P0^0;			  ////  LCD initialization/////
sbit rw=P0^1;
sbit en=P0^2;
sbit edl=P0^3;			 ////  LED array  initialization////
sbit txl=P0^4;
sbit ml=P0^6;
sbit dl=P0^5;
sbit bz=P0^7;
void lcd_inti();
void cmd();
void dat();
void dy();
void dit();
void dah();
void dot_delay();
void main()	
		{
   		edl=0;
		txl=0;
		ml=0;
		dl=0;
		bz=0;
		lcd_inti();
		P2=0x01;
		cmd();
		P1=0x0ff;
		c=0x41;
		d=0x30;
		e=0x20;
		b=0x80;
		P2=b;
		cmd();
		while(1)
			{
			dl=0;
			edl=1;
	if(ch==0)      ////  check whether key (k4) is pressed for entry of alphabets////
				{
				a=c;
				P2=a;
				dat();
				}
				
	if(no==0)	 ////  check whether key (k5) is pressed for entry of numbers////
				{
				a=d;
				P2=a;
				dat();
				}
				
   if(sp==0)      ////  check whether key (k6) is pressed for entry of special 	characters////
				{
				a=e;
				P2=a;
				dat();
				}
   if(up==0)	  ////  check whether key (k2) is pressed for INCREMENTING KEY VALUES ////
				{
				P2=b;
				cmd();
				a++;
				if(a==0x5b)
					{
					a=c;
					}
				
				if(a==0x3a)
					{
					a=d;
					}
				if(a==0x21)				
					{
					a=0x22;
					}  
				
				if(a==0x23)
					{
					a=0x27;
					}
					
				if(a==0x2a)
					{
					a=0x2c;
					}
					
				if(a==0x2F)
					{
					a=0x3F;
					}
					
				if(a==0x40)
					{
					a=e;
					}
				P2=a;
				dat();
				}
   if(dn==0)	 ////  check whether key (k3) is pressed for DECREMENTING KEY  				VALUES ////
				{				
				P2=b;
				cmd();
				a--;
				if(a==0x40)
					{
					a=0x5a;
					}
					
				if(a==0x2f)
					{
					a=0x39;
					}					
				if(a==0x1f)
					{
					a=0x3F;
					} 					
				if(a==0x21)
					{
					a=0x20;
					}
					
				if(a==0x3E)
					{
					a=0x2E;
					} 
					
				if(a==0x2b)
					{
					a=0x29;
					}
					
				if(a==0x26)
					{
					a=0x22;
					}
				P2=a;
				dat();
				}
   if(ok==0)        ////  check whether key (k7) is pressed for the accept the key value ////
				{
				b=b+1;
				P2=b;
				cmd();
				*p=a;
				*p=*p++;
				P2=0x14;
				cmd();
				}
 if(cl==0)	  ////  check whether key (k8) is pressed for the clear the key value ////
			  	{
				b=b-1;
				P2=b;
				cmd();
				P2=0x20;
				dat();
				*p=*p--;
				*p=0;
				P2=0x10;
				cmd();
				}


 if(tx==0)  ////  check whether key (k9) is pressed for transmitting the edited text ////
			  	{
				edl=0;
				txl=1;
				lcd_inti();
				P2=0x0c0;
				cmd();
				P2='T';
				dat();
				P2='X';
				dat();
				for(j=0x80;j<=(b-1);j++)
					{
					f=*q;
					*r=f;
					
				if(f==0x30)	 //// the morse code for the number 0 ////
						{
						dah();
						dah();
						dah();
						dah();
						dah();
						}
						
				if(f==0x31)	//// the morse code for the number 1 ////
						{
						dit();
						dah();
						dah();
						dah();
						dah();
						}
						
				if(f==0x32)	 //// the morse code for the number 2 ////
						{
						dit();
						dit();
						dah();
						dah();
						dah();
						}
				if(f==0x33)	//// the morse code for the number 3 ////
						{
						dit();
						dit();
						dit();
						dah();
						dah();
						}
						
				if(f==0x34)	 //// the morse code for the number 4 ////
						{
						dit();
						dit();
						dit();
						dit();
						dah();
						}

				if(f==0x35)	 //// the morse code for the number 5 ////
						{
						dit();
						dit();
						dit();
						dit();
						dit();
						}

				if(f==0x36)	//// the morse code for the number 6 ////
						{
						dah();
						dit();
						dit();
						dit();
						dit();
						}

				if(f==0x37)	  //// the morse code for the number 7 ////
						{
						dah();
						dah();
						dit();
						dit();
						dit();
						}
				

				if(f==0x38)     //// the morse code for the number 8 ////
						{
						dah();
						dah();
						dah();
						dit();
						dit();
						}

				if(f==0x39)	//// the morse code for the number 9 ////
						{
						dah();
						dah();
						dah();
						dah();
						dit();
						}

				if(f==0x41)	//// the morse code for the character A ////
						{
						dit();
						dah();
						}

				if(f==0x42)      //// the morse code for the character B ////
						{
						dah();
						dit();
						dit();
						dit();
						}

				if(f==0x43)    //// the morse code for the character C ////
						{
						dah();
						dit();
						dah();
						dit();
						}

				if(f==0x44)   //// the morse code for the character D ////	
				  		{
						dah();
						dit();
						dit();
						}

				if(f==0x45)	//// the morse code for the character E ////
						{
						dit();
						}

				if(f==0x46)	//// the morse code for the character F ////
						{
						dit();
						dit();
						dah();
						dit();
						}

				if(f==0x47)	 //// the morse code for the character G ////
						{
						dah();
						dah();
						dit();
						}
				if(f==0x48)	//// the morse code for the character H ////
						{
						dit();
						dit();
						dit();
						dit();
						}

				if(f==0x49)	 //// the morse code for the character I ////
						{
						dit();
						dit();
						}
				if(f==0x4a)	 //// the morse code for the character J ////
						{
						dit();
						dah();
						dah();
						dah();
						}
				if(f==0x4b)	 //// the morse code for the character K ////
						{
						dah();
						dit();
						dah();
						}
				if(f==0x4c)	 //// the morse code for the character L ////
						{
						dit();
						dah();
						dit();
						dit();
						}
				if(f==0x4d)	//// the morse code for the character M ////
						{
						dah();
						dah();
						}
				if(f==0x4e)     //// the morse code for the character N ////
						{
						dah();
						dit();
						}
				if(f==0x4f)	//// the morse code for the character O ////
						{
						dah();
						dah();
						dah();
						}
				if(f==0x50)	//// the morse code for the character P ////
						{
						dit();
						dah();
						dah();
						dit();
						}
				if(f==0x51)	//// the morse code for the character Q ////
						{
						dah();
						dah();
						dit();
						dah();
						}
				


				if(f==0x52)	 //// the morse code for the character R ////
						{
						dit();
						dah();
						dit();
						}
				if(f==0x53)	//// the morse code for the character S ////
						{
						dit();
						dit();
						dit();
						}
				if(f==0x54)	//// the morse code for the character T ////
						{
						dah();
						}
				if(f==0x55)	//// the morse code for the character U ////
						{
						dit();
						dit();
						dah();
						}
				if(f==0x56)	//// the morse code for the character V ////
						{
						dit();
						dit();
						dit();
						dah();
						}
				if(f==0x57)	//// the morse code for the character W ////
						{
						dit();
						dah();
						dah();
						}
				if(f==0x58)	 //// the morse code for the character X ////
						{
						dah();
						dit();
						dit();
						dah();
						}
				



			if(f==0x59)           //// the morse code for the character Y ////
						{
						dah();
						dit();
						dah();
						dah();
						}
				if(f==0x5a)	//// the morse code for the character Z ////
						{
						dah();
						dah();
						dit();
						dit(); 
						}
	      if(f==0x20)        //// the morse code for the special character  SPACE ////
						{
						dah();
						dit();
						dit();
						dit();
						dah();
						} 
if(f==0x22)      //// the morse code for the special character  DOUBLE QUOTES ////
						{
						dit();
						dah();
						dit();
						dit();
						dah();
						dit();
						}  
if(f==0x27)         //// the morse code for the special character  APOSTROPHE ////
						{
						dit();
						dah();
						dah();
						dah();
						dah();
						dit();
						}   
if(f==0x28)	 //// the morse code for the special character  OPEN BRACKETS  ////
						{
						dah();
						dit();
						dah();
						dah();
						dit();
						}  		
if(f==0x29)	 //// the morse code for the special character  CLOSE BRACKETS ////
						{
						dah();
						dit();
						dah();
						dah();
						dit();
						dah();
						}  
	if(f==0x2c)	 //// the morse code for the special character  COMMA ////
						{
						dah();
						dah();
						dit();
						dit();
						dah();
						dah();
						}    
	if(f==0x2d)	   //// the morse code for the special character  HYPHEN ////
						{
						dah();
						dit();
						dit();	
						dit();
						dit();
						dah();
						}    
						       
	if(f==0x2e)	 //// the morse code for the special character  FULL STOP ////
						{
						dit();
						dah();
						dit();
						dah();
						dit();
						dah();
						}       
	if(f==0x3f)   //// the morse code for the special character  QUESTION MARK ////
						{
						dit();
						dit();
						dah();
						dah();
						dit();
						dit(); 
						}  
					&q==&q++;
					&r==&r++;
					}					
					P2=0x01; 	  //// lcd clr screen ////
					cmd();			
					b=0x80;
					P2=b;
					cmd();
					txl=0;
					dl=1;
					bz=0; 
					p=0x30;
					q=0x30;
					r=0x40;
				   }
				dy();				
 }
 }
 
 void lcd_inti()		  		 //// lcd initialisition  cmds ////
	    {
		P2=0x38;
		cmd();
		P2=0x0e;
		cmd();	
		}
 void dy()							 //// delay ////
		{ 
		for(i=0;i<=20000;i++);
		}

 void cmd()						 //// lcd cmd mode ////
		{ 
		dy(); /*delay for LCD ready*/
		rs=0; /*rs=0 for command*/
		rw=0; /*rw=0*/
		en=1; /*enable=1*/
		en=0; /*enable=0*/
		}
 void dat()						 //// lcd data mode ////
		{ 
		dy(); /*delay for LCD ready*/
		rs=1; /*rs=1 for command*/
		rw=0; /*rw=0 */
		en=1; /*enable=1*/
		en=0; /*enable=0*/
		}
 void dit()					//// morse code dit function ////
		{
		bz=0;
		ml=0;
		dot_delay();
		bz=1;
		ml=1;
		dot_delay();
		bz=0;
		ml=0;
		dot_delay();
		}
 void dah()					 //// morse code dah function ////
		{
		bz=0;
		ml=0;
		dot_delay();
		bz=1;
		ml=1;
		dot_delay();
		dot_delay();
		dot_delay();
		bz=0;
		ml=0;
		dot_delay();
		}


 void dot_delay()				 //// morse code dot delay function ////

		{		
		for(g=0;g<=16;g++)

			{
			for(h=0;h<=2000;h++);
			}

		}