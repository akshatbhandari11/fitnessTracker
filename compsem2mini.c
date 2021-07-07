#include <stdio.h>
#include <string.h>
#include <time.h>

void disp();
void entry();
void rating();
int calcpro(int x,int y );
int calccarb(int x,int y );
int calcfat(int x,int y );
int calccal(int x,int y );
void giveSuggestions(int proteinStars, int carbStars, int fatStars, int calorieStars);

int main()
{
    int choice;
    printf("1.ENTER YOUR MACROS\n");
    printf("2.RATE MY MEAL\n");
    printf("ENTER YOUR OPTION\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:entry();
        break;
        case 2:rating();
        break;
        default:
        printf("lol");
        break;
    }
    return(0);


}

void entry()
{
	time_t s, val = 1;
    struct tm* current_time;
    s = time(NULL);
    current_time = localtime(&s);
    char name[50];
    int age,date,weight,calorie,protein,carbohydrates,n;
    FILE* fp = fopen("GfgTest.csv","a+");

    if (!fp)
        printf("Can't open file\n");

    else {
        printf("\nEnter the  Name\n");
        scanf("%s", &name);
        printf("\nEnter age\n");
        scanf("%d", &age);
        printf("WELCOME TO NUTRICHOISE %s \n:)",name);
        printf("TIME : %02d:%02d:%02d\n",
            current_time->tm_hour,
            current_time->tm_min,
            current_time->tm_sec);

        printf("how can i help you :) \n");
        printf("\nPlease enter weight\n");
        scanf("%d", &weight);
        printf("\nPlease enter the calories burnt\n");
        scanf("%d", &calorie);
        printf("\nPlease enter the amount of protein\n");
        scanf("%d", &protein );
        printf("\nPlease enter the amount of carbohydrates\n");
        scanf("%d", &carbohydrates);
        fprintf(fp, "%d/%d/%d, %dJ, %dg/L, %dkJ\n",current_time->tm_mday,current_time->tm_mon + 1,current_time->tm_year + 1900,weight,calorie,protein,carbohydrates);
        printf("\nNew Account added to record\n");
        fclose(fp);
        disp();
	}
    return;
}

void disp()
{   
    char buffer[1024];
    int row = -1;
    int column = 0;
	FILE* fp = fopen("GfgTest.csv","a+");

	while (fgets(buffer,1024, fp))
	{     column = 0;
			row++;
            if (row == 0)
                continue;
            char* value = strtok(buffer, ", ");

            while (value) {
                // Column 1
                if (column == 0) {
                    printf("date:");
                }

                // Column 2
                if (column == 1) {
                    printf("\tweight :");
                }

                // Column 3
                if (column == 2) {
                    printf("\tcalorie :");
                }


                // Column 4
                if (column == 3) {
                    printf("\tprotein:");
                }


                // Column 5
                if (column == 4) {
                    printf("\tcarbohydrates:");
                }
                printf("%s", value);
                value = strtok(NULL, ", ");
                column++;

            }
            printf("\n");
	}

    fclose(fp);
}
void rating()
{
    int gen,pro,carb,fat,cal,i;
    printf("ENTER 1 FOR MALE AND 2 FOR FEMALE:\n");
    scanf("%d",&gen);
    printf("ENTER THE AMOUNT OF PROTEIN(in grams):\n");
    scanf("%d",&pro);
    printf("ENTER THE AMOUNT OF CARBOHYDRATES(in grams):\n");
    scanf("%d",&carb);
    printf("ENTER THE AMOUNT OF FATS(in grams):\n");
    scanf("%d",&fat);
    printf("ENTER THE AMOUNT OF CALORIES(in KILOJOULES):\n");
    scanf("%d",&cal);
    printf("SCALE:OUT OF 10:");
    printf("\n    PROTEIN  :");

    int proteinStars = calcpro(gen,pro);
    int carbStars = calccarb(gen,carb);
    int fatStars = calcfat(gen,fat);
    int calorieStars = calccal(gen,cal);

    for(i=1;i<=proteinStars;i++)
    {
        printf("*");
    }
    printf("\nCARBOHYDRATES:");
        for(i=1;i<=carbStars;i++)
    {
        printf("*");
    }
    printf("\n   FATS      :");
        for(i=1;i<=fatStars;i++)
    {
        printf("*");
    }
    printf("\n  CALORIES   :");
        for(i=1;i<=calorieStars;i++)
    {
        printf("*");
    }

    printf("\n");
    giveSuggestions(proteinStars, carbStars, fatStars, calorieStars);

    return;
}


int calcpro(int x,int y)
{
    int calcedpro,calcpromod;



    if(x==1)
    {
        calcedpro=(y*100)/156;
        calcpromod=calcedpro/10;
        return(calcpromod);
    }
    else if(x==2)
    {
        calcedpro=(y*100)/125;
        calcpromod=calcedpro/10;
        return(calcpromod);
    }
    else
    {
        printf("invalid choice");
        return(0);
    }
}

int calccarb(int x,int y)
{
    int calcedcarb,calccarbmod;


    if(x==1)
    {
        calcedcarb=(y*100)/343;
        calccarbmod=calcedcarb/10;
        return(calccarbmod);
    }
    else if(x==2)
    {
        calcedcarb=(y*100)/275;
        calccarbmod=calcedcarb/10;
        return(calccarbmod);
    }
    else
    {
        printf("invalid choice");
        return(0);
    }
}

int calcfat(int x,int y)
{
    int calcedfat,calcfatmod;


    if(x==1)
    {
        calcedfat=(y*100)/125;
        calcfatmod=calcedfat/10;
        return(calcfatmod);
    }
    else if(x==2)
    {
        calcedfat=(y*100)/100;
        calcfatmod=calcedfat/10;
        return(calcfatmod);

    }
    else
    {
        printf("invalid choice");
        return(0);
    }
}

int calccal(int x,int y)
{
    int calcedcal,calccalmod;


    if(x==1)
    {
        calcedcal=(y*100)/2500;
        calccalmod=calcedcal/10;
        return(calccalmod);
    }
    else if(x==2)
    {
        calcedcal=(y*100)/2000;
        calccalmod=calcedcal/10;
        return(calccalmod);
    }
    else
    {
        printf("invalid choice");
        return(0);
    }
}

void giveSuggestions(proteinStars, carbStars, fatStars, calorieStars){
    char* protienImp = "Protein is one of a complex group of molecules that do all kinds of jobs in your body. They make up your hair, nails, bones, and muscles. Protein gives tissues and organs their shape and also helps them work the way they should. In short, protein is one of the building blocks that make you into who you are.";
    char* carbsImp = "Carbohydrates are your body's main source of energy: They help fuel your brain, kidneys, heart muscles, and central nervous system. Your body breaks down carbohydrates into glucose. Glucose, or blood sugar, is the main source of energy for your body's cells, tissues, and organs.";
    char* fatsImp = "A small amount of fat is an essential part of a healthy, balanced diet. Fat is a source of essential fatty acids, which the body cannot make itself. Fat helps the body absorb vitamin A, vitamin D and vitamin E. These vitamins are fat-soluble, which means they can only be absorbed with the help of fats.";
    char* calorieImp = "Your body needs calories just to operate to keep your heart beating and your lungs breathing. Most adults need a minimum of 2000 calories to sustain metabolism, muscle activity, and brain function.";

    char* protienRisks = "However, extra protein is not used efficiently by the body and may impose a metabolic burden on the bones, kidneys, and liver. Moreover, high-protein/high-meat diets may also be associated with increased risk for coronary heart disease due to intakes of saturated fat and cholesterol or even cancer";
    char* carbsRisks = "However, if you overdo the carbs, your blood sugar levels can get too high. This causes your body to make more insulin, which tells your cells to save the extra glucose as fat. That can be unhealthy if you're already carrying a few extra pounds. It can lead to diabetes and other related health issues.";
    char* fatsRisks = "However, eating too much saturated fats in your diet can raise 'bad' LDL cholesterol in your blood, which can increase the risk of heart disease and stroke. 'Good' HDL cholesterol has a positive effect by taking cholesterol from parts of the body where there's too much of it to the liver, where it's disposed of.";
    char* calorieRisk = "However, consuming more calories than you burn may cause you to become overweight or obese. This increases your risk for cancer and other chronic health problems. Overeating -- especially unhealthy foods -- can take its toll on your digestive system.";

    if (proteinStars <= 5)
        printf("Your diet does not have enough proteins! %s\n", protienImp);
    else if (proteinStars > 5 && proteinStars <= 9)
        printf("Your protein intake is almost the perfect level. Don't give up, have some more! %s\n", protienImp);
    else if (proteinStars == 10)
        printf("Woohooo! You did it. Perfect score on proteins");
    else
        printf("TOO MANY PROTEINS!!! %s\n", protienRisks);
    

    if (carbStars <= 5)
        printf("You're not taking enough carbohydrates! %s\n", carbsImp);
    else if (carbStars > 5 && carbStars <= 9)
        printf("Your carbohydrate intake is almost the perfect level. Don't give up, have some more! %s\n", carbsImp);
    else if (carbStars == 10)
        printf("Woohooo! You did it. Perfect score on carbohydrates");
    else
        printf("TOO MANY CARBS!!! %s\n", carbsRisks);

    if (fatStars <= 5)
        printf("Don't slack off on fats! They can be good too! %s\n", fatsImp);
    else if (fatStars > 5 && fatStars <= 9)
        printf("Your fats intake is almost the perfect level. Don't give up, have some more! %s\n", fatsImp);
    else if (fatStars == 10)
        printf("Woohooo! You did it. Perfect score on fats");
    else
        printf("TOO MANY FATS!!! %s\n", fatsRisks);

    if (calorieStars <= 5)
        printf("Amp up your calorie game! %s\n", calorieImp);
    else if (calorieStars > 5 && calorieStars <= 9)
        printf("Your calorie intake is almost the perfect level. Don't give up, have some more! %s\n", calorieImp);
    else if (calorieStars == 10)
        printf("Woohooo! You did it. Perfect score on calories");
    else
        printf("TOO MANY CALORIES!!! %s\n", calorieRisk);
}


