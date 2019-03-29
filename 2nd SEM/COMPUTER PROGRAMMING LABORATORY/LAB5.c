#include<stdio.h>
#include<string.h>

void main()
{  
   int cust_no, unit_con;
   float charge,surcharge=0, amt, total_amt;
   char nm[25];
   
   printf("Enter the customer IDNO :\t");
   scanf("%d",&cust_no);
   printf("Enter the customer Name :\t");
   scanf("%s",nm);
   printf("Enter the unit consumed by customer  :\t");
   scanf("%d",&unit_con);

   if (unit_con <200 )
      charge = 0.80;
   else if (unit_con>=200 && unit_con<300)
      charge = 0.90;
   else
      charge = 1.00;

   amt = unit_con*charge;
   if (amt>400)
      surcharge = amt*15/100.0;
   total_amt = amt+surcharge;
   
   printf("\t\t\t\nElectricity Bill\n\n");
   printf("Customer IDNO                       :\t%d",cust_no);
   printf("\nCustomer Name                       :\t%s",nm);
   printf("\nunit Consumed                       :\t%d",unit_con);
   printf("\nAmount Charges @Rs. %4.2f  per unit  :\t%0.2f",charge,amt);
   printf("\nSurchage Amount                     :\t%.2f",surcharge);
   printf("\nMinimum meter charge Rs             :\t%d",100);
   printf("\nNet Amount Paid By the Customer     :\t%.2f",total_amt+100);
}
