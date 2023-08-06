//base class personal information

#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>
using namespace std;
void fordelay(long unsigned int j)
{ 
    int i,k;
    for(i=0;i<j;i++)
    k=i;
}
//base class1
class personal{
    
    int age;
    int job;
    int gender;//f/m/nb
    string hobbies[10];
    public:
    string name;
    void personal1()
    {
        cout<<"Enter your name:"<<endl;
        fflush(stdin);
        getline(cin,name);
        fflush(stdin);
        cout<<"Enter age:"<<endl;
        cin>>age;
        cout<<"Enter your job\n1.student\n2.working\n3.unemployed:"<<endl;
        cin>>job;
        cout<<"Enter gender\n1.female\n2.male\n3.non-binary:"<<endl;
        cin>>gender;
        char c;
        do{
            static int i=0;
            cout<<"Enter hobbies:"<<endl;
            fflush(stdin);
            cin>>hobbies[i];
            fflush(stdin);
            i++;
            cout<<"Want to enter more(y/n):"<<endl;
            fflush(stdin);
            cin>>c;
        }while(c=='y');
    }
    string na()
    {
        return name;
    }
    int gen()
    {
        return gender;
    }
    int job1()
    {
        return job;
    }
    virtual void save(fstream& out)
    {
        out<<"Personal information."<<endl<<endl;
        out<<"Name : "<<name<<endl<<"Age : "<<age<<endl;
        if(job==1)
        {out<<"Job : Student"<<endl;}
        else if(job==2)
        {out<<"Job : Working"<<endl;}
        else
        {out<<"Job : Unemployed"<<endl;}
        if(gender==1)
        {out<<"Gender : Female"<<endl;}
        else if(gender==2)
        {out<<"Gender : Male"<<endl;}
        else
        {out<<"Gender : Non-binary"<<endl;}
    }
    virtual void analysis(){}
    //working, studying
};

//class for family related questions
class family:virtual public personal
{
    int type_of_family;
    int number_of_members;
    int marital_status;
    public:
    int pet;
    int signi_other;
    int no_of_working;
    int marital_affair;
    int no_of_children;
    int happyp;
    string hap1;
    string sat;
    int div;
    string happ1[20];
    string happ2[20];
    char ch;

    family()
    {
        cout<<"Type of family\n1.joint family\n2.nuclear family:"<<endl;
        cin>>type_of_family;
        cout<<"Number of members:"<<endl;
        cin>>number_of_members;
        cout<<"Marital_status\n1.married\n2.unmarried\n3.divorced\n4.widow/widower:"<<endl;
        cin>>marital_status;
    }
    void save(fstream& out)
    {
        out<<endl<<endl<<"Some of your information regarding family."<<endl<<endl;
        if(type_of_family==1)
        out<<"Type of family: Joint family"<<endl;
        else
        out<<"Type of family: Nuclear family"<<endl;
        out<<"Number of family members : "<<number_of_members<<endl;
        if(marital_status==1)
        {out<<"Marital status : Married"<<endl;}
        else if(marital_status==2)
        {out<<"Marital status : Unmarried"<<endl;}
        else if(marital_status==3)
        {out<<"Marital status : Divorced"<<endl;}
        else
        {
            if(gen()==1)
            {out<<"Marital status : widower"<<endl;}
            else
            {
                out<<"Marital status : widow"<<endl;
            }
        }
    }
    void quest()
    {
        cout<<"Do you have a pet?\n1.yes\n2.no:"<<endl;
        cin>>pet;
        cout<<"Do you have a significant other?\n1.yes\n2.no:"<<endl;
        cin>>signi_other;
        if(number_of_members>1)
        {cout<<"How many members in the family are working:"<<endl;
        cin>>no_of_working;
        cout<<"Are you happy with your family\n1.yes\n2.no"<<endl;
        cin>>happyp;
        if(happyp==2)
        {
            cout<<"Is it because of a person in the family or something else(person/yourself):"<<endl;
            fflush(stdin);
            cin>>hap1;
            fflush(stdin);
            if(hap1=="person")
            {
                int i=0;
                cout<<"How does that family member affect you:"<<endl;
                do{
                    fflush(stdin);
                    getline(cin,happ1[i]);
                    i++;
                    cout<<"Do you want to enter more(y/n):";
                    fflush(stdin);
                    cin>>ch;
                }while(ch=='y');
            }
            else{
                int i=0;
                cout<<"What problems do you face:";
                do
                {
                    fflush(stdin);
                    getline(cin,happ2[i]);
                    i++;
                    cout<<"Do you want to continue(y/n):";
                    cin>>ch;
                } while (ch=='y');
            }
        }
        }
        if(marital_status==1)
        {
        cout<<"How many children:"<<endl;
        cin>>no_of_children;
        cout<<"Do you have extra marital affair\n1.yes\n2.no:"<<endl;
        cin>>marital_affair;
        }
        else if(marital_status==3)
        {
            cout<<"What circumstances led to your divorce\n1.Yourself\n2.Significant Other\n3.External Circumstances:"<<endl;
            cin>>div;
            cout<<"Are you satisfied with your life after divorce(y/n):"<<endl;
            fflush(stdin);
            cin>>sat;
        }
        
    }
    void analysis()
    {
        if(happyp==2)
        {
            if(hap1=="person")
            {
                cout<<endl<<endl;
                cout<<"Try talking to the said person and work on solving your problem together."<<endl;
                cout<<"Sometimes, a lot of problems can occur due to communication gaps.\nSo telling each other how we feel is really important."<<endl;
                cout<<"If even after talking things don't work out, don't stress about it.\nLet it cool down.\nLet it go."<<endl;
                cout<<"If letting it go is not possible, then try not to indulge with them too much."<<endl;
                cout<<"You are enough as you are."<<endl;
            }
            else
            {
                cout<<endl<<endl;
                cout<<"We are grateful that you are here today.\nSometimes, we are unhappy with what we do and who we are."<<endl;
                cout<<"And it's ok.\nSometimes, we have to fall down to rise up.\nOnly one thing is important right now and it's you."<<endl;
            }
        }
        else
        {
            cout<<"We are glad to know that you are surrounded by people you love all the time.\n";
            cout<<"We are excited for you to make so many happy memories."<<endl;
        }
    }
    
};

//class for education 
class academics{
   public:
   string max_degree_achieve;//switch case
   string extra_curricular;
   academics()
   {
    cout<<"Enter maximum degree achieved:";
    fflush(stdin);
    getline(cin,max_degree_achieve);
    cout<<"Enter any extra curricular in which you are engaged(like sports, dancing, organizing etc):"<<endl;
    fflush(stdin);
    getline(cin,extra_curricular);
    fflush(stdin);
   }
   //academics will be used for all the 3 options 
   
};

class student:public academics,virtual public personal
{
    int stress_level;//switch case
    int avg_level;
    public:
    string aspire;
    char ch;
    int pp;
    char happ;
    string study_routine;
    int no_of_hours;
    student()
    {
        cout<<"Do you feel any stress ,if yes then rate yourself from 1-5 else write 0:"<<endl;
        cin>>stress_level;
        cout<<"How would you rate yourself as a student\n1.above average\n2.average\n3.below average:"<<endl;
        cin>>avg_level;
        //if you study more and does not score-lack and disciplined
        cout<<"You prefer to study just before exams or on daily basis(jbe/db):"<<endl;
        fflush(stdin);
        cin>>study_routine;
        fflush(stdin);
        cout<<"Enter number of hours you self-study in a week:"<<endl;
        cin>>no_of_hours;
        cout<<"Do you enjoy studying(y/n):"<<endl;
        fflush(stdin);
        cin>>happ;
        fflush(stdin);
        cout<<"Do you feel peer pressure rate yourself(1-5):"<<endl;
        cin>>pp;
        cout<<"What do you aspire to be:"<<endl;
        fflush(stdin);
        getline(cin,aspire);
        fflush(stdin);
        cout<<"Are you working to be "<<aspire<<" (y/n)"<<endl;
        fflush(stdin);
        cin>>ch;
        fflush(stdin);
    }
    void save(fstream& out)
    {
        out<<endl<<"Details related to your work."<<endl;
        out<<"Maximum degree you have achieved : "<<max_degree_achieve<<endl;
        out<<"Extra curricular activities in which you are involved are : "<<endl;
        out<<extra_curricular<<endl;
    }
    
    void analysis()
    {
        if(stress_level==1 || stress_level==2 || stress_level==3)
        {
            cout<<"Sometimes, a lot of things happen together and we get overwhelmed."<<endl;
            cout<<"In such a situation, it is best to take one step forward at a time."<<endl;
            cout<<"It can be harder to achieve a lot of goals in a short period of time."<<endl;
            cout<<"So, set smaller and achievable goals."<<endl;
        }
        else if(stress_level==4 || stress_level==5)
        {
            cout<<"We understand that things can be hard right now."<<endl;
            cout<<"Take sometime out for yourself, go for a walk, or talk to a loved one or spend time doing things you love like painting or eating something like."<<endl;
            cout<<"At such a stage, it is important for you to treat yourself well."<<endl;
        }
        else
        {cout<<endl;}
        if(avg_level==1)
        {cout<<"We are happy that you feel this confident about your grades."<<endl;}
        else if(avg_level==2)
        {cout<<"We must let you know that being average is ok, it's normal.\nRemember things only go up from here."<<endl;}
        else
        {cout<<"Don't you worry, all good things come in time and work a little harder and you will see your grades rise."<<endl;}
        if(study_routine=="jbe" && avg_level==3)
        {cout<<"You should work a little on changing your habits.\nAlways studying at the last moment creates high levels of stress in your body and your body goes into survival mode."<<endl;
        cout<<"Studying everyday might not show instant results but we all know ROME WAS NOT BUILT IN A DAY."<<endl;}
        if(no_of_hours<14)
        {cout<<"Try to increase a little bit of self-study time each day, for better results."<<endl;}
        else if(no_of_hours>=14 && no_of_hours<25)
        {cout<<"Good job, CONGRATULATIONS!! We are proud of you for giving adequate number of hours for your future each day."<<endl;}
        else
        {cout<<"Try to loosen up a little giving more hours than required to self-studying is also not good.\nYou only live once."<<endl;}
        if(pp==1 ||  pp==2 || pp==3)
        {
            cout<<"This amount of peer pressure is good."<<endl;
            cout<<"It creates an environment of positive competition."<<endl;
            cout<<"This can lead to better results."<<endl;
        }
        else
        {
            cout<<"Such a level of peer pressure can give rise to negativity."<<endl;
            cout<<"Be sure to remember that you are not actually competing others, it is just a way of helping and motivating each other."<<endl;
            cout<<"Sometimes, we do a lot of things under peer pressure, remember your own choices and beliefs and where you come from."<<endl;
            cout<<"It is important to keep your self-identity safe. Don't do anything just because somebody thinks you should."<<endl;
        }
    }
};


class working:virtual public personal
{
    int income;
    string work_from;
    string work;
    char ch;
    string business;
    string sat;
    string job1;
    public:
    working()
    {
        cout<<"You have your own business or have job:"<<endl;
        fflush(stdin);
        cin>>business;
        fflush(stdin);
        cout<<"Annual income(0-if you do not want to enter):"<<endl;
        cin>>income;
        cout<<"Do you work from home(wfh) or from office(off):"<<endl;
        fflush(stdin);
        cin>>work_from;
        fflush(stdin);
        cout<<"You perform well while working alone(alone) or in a team(team):"<<endl;
        fflush(stdin);
        cin>>work;
        fflush(stdin);
        cout<<"Is there any work related stress(y/n):"<<endl;
        fflush(stdin);
        cin>>ch;
        fflush(stdin);
        cout<<"Are you satisfied with your income(yes/no):"<<endl;
        fflush(stdin);
        cin>>sat;
        fflush(stdin);
        cout<<"Are you satisfied with your job(yes/no):"<<endl;
        fflush(stdin);
        cin>>job1;
    }
    void save(fstream& out)
    {
        out<<endl<<"Details related to your work."<<endl;
        if(business=="business")
        out<<"You own a business."<<endl;
        else
        {out<<"You have a job."<<endl;}
        out<<"Annual income : "<<income<<endl;
    }
    void analysis()
    {
        if(work_from=="wfh")
        {cout<<"We are happy to hear that you are comfortably working within the walls of your house."<<endl;
        cout<<"Working from home can be a big task as there are no clear boundaries between professional and personal lives."<<endl;
        }
        else
        {
            cout<<"Congratulations! On this job, because jobs are hard to find in such a fast paced world."<<endl;
            cout<<"It is important to remember that you don't work alone and what you do can affect a large number of people."<<endl;
            cout<<"So be mindful of all the things you do."<<endl;
        }
        if(work=="alone")
        {cout<<"It is good to know that you can handle all your work alone but just know that it's ok if you need somebody's help sometimes."<<endl;
         cout<<"While working it's possible you are put into teams so it is better to prepare yourself for such situations also."<<endl;}
        else
        {cout<<"Great! Not everybody is great at working in teams."<<endl;
        cout<<"This is a great quality for people who want to work at higher posts."<<endl;}
        if(ch=='y')
        {cout<<"This is not surprising, as we interact with lot of people with different opinions at work."<<endl;
        cout<<"Such situations are normal and all we can do is wait for them to pass through."<<endl;}
        if(sat=="no" && job1=="no")
        {
            cout<<"Since you are not happy with your job and even with your income so only thing you can do is change you job and take a step towards what you like."<<endl;
            cout<<"It is important to enjoy what you do, income is only secondary."<<endl;
        }
    }
};

//class for social life
class social_life:virtual public personal
{
    int no_friends;
    int real_friends;
    int active;
    int out;
    string gowith;
    string role;
    public:
    social_life()
    {
        cout<<"How many friends do you have?"<<endl;
        cin>>no_friends;
        cout<<"Interesting!! Everyone has friends but only some are real."<<endl;
        cout<<"So, if a situation arises, then how many of you friends you think will stay to help you:"<<endl;
        cin>>real_friends;
        cout<<"How often do you like to go out in a week(number of days)?"<<endl;
        cin>>out;
        cout<<"Do you prefer to go out alone or with somebody?"<<endl;
        fflush(stdin);
        cin>>gowith;
        fflush(stdin);
        cout<<"What role does social media play in your life?"<<endl;
        fflush(stdin);
        getline(cin,role);
        fflush(stdin);
        cout<<"How active you are on social media?\n1.Inactive\n2.Moderately Active\n3.Pro Active:"<<endl;
        cin>>active;
    }
    void analysis()
    {
        if(real_friends>=1)
        {cout<<"It makes us happy to know that you have a shoulder to lean on when things get hard."<<endl;}
        else
        {cout<<"It can feel like you have no one and that you have face this all alone but just know that there is light after the dark."<<endl;}
        if(out>3)
        {
            cout<<"Going out so many times a week means that you have a lot of friends to catch up on\nBut it can also mean that you are trying to run away from who you are now."<<endl;
            cout<<"It indicates unstability, it is not healthy to go out so frequently."<<endl;
        }
        if(gowith=="alone")
        {
            cout<<"This indicates that you are independent and you are comfortable in your own skin."<<endl;
        }
        else
        {
            cout<<"If every time you go out is with somebody else it can indicate that you do not like spending time with yourself."<<endl;
        }
    }
};

//class for health
class body_health:virtual public personal
{
    string have_any_health_currently;
    string previously_health; 
    string before;
    string before1;
    string diabetic;
    string bp;
    string heart;
    string other;
    int exercise;
    int times;//time //what you do
    int avg_sleep;
    int weight;//underweight/overweight
    float height;
    int wake_up_time;
    int gen1;
    string length;
    float bmi;
    string ovhealth;
    int immune;
    public:
    body_health()
    {
        cout<<"Enter your weight(in kg):"<<endl;
        cin>>weight;
        cout<<"Enter your height(in m):"<<endl;
        cin>>height;
        bmi=(weight)/(height*height);
        cout<<"Do you currently have any health issues(y/n):"<<endl;
        cin>>have_any_health_currently;
        if(have_any_health_currently=="y" || have_any_health_currently=="Y")
        {
            cout<<"Are you diabetic:"<<endl;
            fflush(stdin);
            cin>>diabetic;
            cout<<"Do you blood pressure related issue:"<<endl;
            fflush(stdin);
            cin>>bp;
            cout<<"Is it a heart realated issue:"<<endl;
            fflush(stdin);
            cin>>heart;
            cout<<"other:"<<endl;
            fflush(stdin);
            cin>>other;
        }
        else 
        {
            cout<<"Have you ever had any health issues before:"<<endl;
            fflush(stdin);
            cin>>before;
            if(before=="y" || before=="Y")
            cout<<"Please, write them down below:"<<endl;
            fflush(stdin);
            getline(cin,before1);
        }
        cout<<"How many days do you exercise/yoga in a week:"<<endl;
        cin>>times;
        cout<<"Do your weekly workouts include the following:\n1.Yoga\n2.Cardio\n3.Weightlifting\n4.Any sport\n5.Walking:"<<endl;
        cin>>exercise;
        cout<<"What is your average sleep time in a day:"<<endl;
        cin>>avg_sleep;
        cout<<"At what time you start your day?"<<endl;
        cin>>wake_up_time;
        cout<<"Rate your immunity from 1-5:"<<endl;
        cin>>immune;
        gen1=gen();
        if(gen1==1)
        {
            cout<<"What is your menstruation cycle length:"<<endl;
            fflush(stdin);
            getline(cin,length);
            cout<<"Do you have any ovarian health issues:"<<endl;
            cin>>ovhealth;
        }
    }
    void save(fstream& out)
    {
        out<<endl<<"Details related to your body."<<endl;
        out<<"Weight : "<<weight<<endl;
        out<<"Height : "<<height<<endl;
        out<<"Body mass index as calculated: "<<bmi<<endl;
    }
    void analysis()
    {
        if(bmi<=18.5)
        {
            cout<<"The BMI informs us that you are underweight.\nIt is advised that you should maintain a balanced and healthy diet."<<endl;
        }
        else if(bmi>18.5 && bmi<24.9)
        {
            cout<<"The BMI informs us that you have the adequate weight accourding to your height."<<endl;
        }
        else if(bmi>=24.9 && bmi<29.9)
        {
            cout<<"The BMI informs us that you are overweight.\nYou should concentrate more on eating healthy and exercising."<<endl;
        }
        else
        {
            cout<<"You have reached the stage of obesity which is not at all good for your health."<<endl;
            cout<<"You should reach out to a nutritionist as soon as possible to construct a diet plan for you to start losing weight."<<endl;
            cout<<"It is advisable to start immediately as obesity attracts a lot of diseases."<<endl;
        }
        if(bmi>24.9 && have_any_health_currently=="y")
        {
            cout<<"According to the information filled earlier, you also have some health issues currently."<<endl;
            cout<<"You are at an even higher risk of getting other diseases at a stage like this."<<endl;
            cout<<"Visit a doctor as soon as possible."<<endl;
        }
        if(times>3)
        {
            cout<<"It is appreciable that you exercise on a regular basis.\nKeep it up."<<endl;
        }
        else
        {
            cout<<"You should start getting some body movement everday."<<endl;
        }
        if(avg_sleep<6)
        {
            cout<<"We know that a lot is happening in life right now, but remember to priortize youself at your sleep."<<endl;
            cout<<"Atleast try to have 7-8 hours of sleep in a day."<<endl;
        }
        if(wake_up_time>10)
        {
            cout<<"Try to wake up early, the silence of the morning will calm your mind and help you think clearly."<<endl;
        }
    }
};

//class for mental health
class mental_health:virtual public personal
{
    string over;
    int angry;
    char med;
    int troub;
    int feel;
    int let;
    string harm;
    string rea;
    char ple;
    char pro;
    int time;
    public:
    mental_health()
    {
        cout<<"Are you feeling overwhelmed or stressed(y/n):"<<endl;
        fflush(stdin);
        getline(cin,over);
        cout<<"How frequently do you feel angry in a week?"<<endl;
        cin>>angry;
        cout<<"Do you meditate(y/n):"<<endl;
        fflush(stdin);
        cin>>med;
        cout<<"Are you facing trouble concentrating on things, such as reading the newspaper or watching television:"<<endl;
        cout<<"1.not at all\n2.several days\n3.nearly everyday:"<<endl;
        cin>>troub;
        cout<<"Do you feel bad about yourself- or that you are a failure or have let yourself or your family down:"<<endl;
        cout<<"1.Not at all\n2.Several days\n3.Nearly everyday:"<<endl;
        cin>>feel;
        cout<<"Do you always feel let down by yourself and others:"<<endl;
        cout<<"1.Yes\n2.No\n3.Sometimes:"<<endl;
        cin>>let;
        cout<<"Have you ever tried to self-harm(y/n):"<<endl;
        fflush(stdin);
        cin>>harm;
        if(harm=="y")
        {
            cout<<"What was the biggest reason behind this?"<<endl;
            fflush(stdin);
            getline(cin,rea);
        }
        cout<<"Do you try to please others(y/n):"<<endl;
        cin>>ple;
        cout<<"Do you procastinate(y/n):"<<endl;
        cin>>pro;
        cout<<"How many times a week do you spend time with youself.\n1.Everyday\n2.Every alternate day\n3.Never:"<<endl;
        cin>>time;
    }
    void analysis()
    {
        if(over=="y")
        {
            if(angry>=3)
            {
                cout<<"There is a possibility that you are unwilling dealing with a lot of things that is causing you to be irritable and angry."<<endl;
            }
            else
            {
                cout<<"It's good that you're able to keep your anger under control when needed,sometimes unecessary anger causes a lot of problems."<<endl;
            }
        }
        if(troub==1)
        {
            cout<<"We are glad to know that you're not facing any concentration problems, but we should let you know that sometimes it's okay to feel frustrated."<<endl;
        }
        else if(troub==2)
        {
            cout<<"Feeling frustrated some days is normal, but keep an eye open so that you realise as soon as you think the frustration is going out of hand, you can control."<<endl;
        }
        else
        {
            cout<<"Feeling frustrated so frequently can be a sign of various things. Like you are not enjoying what you are doing, being mentally tired, wanting to be somewhere else etc.."<<endl;
            cout<<"Whenever you start to feel frustrated, try a process called grounding, it means to count 5 things you can see, hear and feel at that particular moment."<<endl;
            cout<<"It helps in calming of the mind."<<endl;
        }
        if(feel==1)
        {
            cout<<"We are very proud of you, to know that you feel good about yourself. It is a necessary quality required in this generation."<<endl;
        }
        else if(feel==2)
        {
            cout<<"Sometimes, the burden we carry pulls us down, it is not okay to feel bad about yourself.\nYou deserve to be loved just like anybody else."<<endl;
        }
        else
        {
            cout<<"When a person feels like a failure,he/she forgets that they are also a person and that they are allowed to feel pain and happiness like a normal person."<<endl;
            cout<<"At times, the weight of expectations lies on our shoulder, and we are unable to stand against it."<<endl;
            cout<<"It is at that time that we should remind ourselves of our achievements as well as victories, evenif they are small."<<endl;
        }
        if(ple=='y')
        {
            cout<<"Pleasing others can stem from feeling insecure with yourself and feeling unsafe."<<endl;
            cout<<"Try to bring to mind what you yourself want before making decisions rashly."<<endl;
        }
        if(pro=='y')
        {
            cout<<"Procastination is not laziness to do something."<<endl;
            cout<<"It might look like that but it has a deeper reason. one of the main causes of procastination is fear of failure."<<endl;
            cout<<"Every now and then its okay to procastinate but try to get help when you realise its getting too much."<<endl;
        }
        if(time<=4)
        {
            cout<<"In this fast paced world, it can be hard to find time for your own self."<<endl;
            cout<<"So to find out more about yourself spend sometime with youself."<<endl;
            cout<<"Even 20  minutes a day is enough."<<endl;
        }
    }
};


int main()
{
    fstream file;
    file.open("Secured.txt", ios::in | ios::out);
    int day;
    int often;
    system("cls");
    system("color 5");
    cout<<"-----------------------------WELCOME--------------------------------";
    cout<<endl<<endl;
    cout<<"----------------------Psychological Evaluation----------------------";
    cout<<endl<<"Good afternoon."<<endl;
    cout<<"Heyy buddy!! How was your day today \n1.Awesome\n2.Good\n3.Better\n4.Bad:"<<endl;
    cin>>day;
    if(day==1)
    {cout<<"Great."<<endl;}
    else if(day==4)
    {cout<<"How often do you feel this\n1.Everyday\n2.Half of the week\n3.Half of the month:"<<endl;
     cin>>often;
     cout<<"Don't be upset, we will try to figure it out together."<<endl;}
    else{
        cout<<"Let's make it awesome from now."<<endl;
    }
    cout<<"So, Let's get going."<<endl;
    cout<<"First let's start up with knowing some of your basic information."<<endl;
    fordelay(1000000000000000);
    cout<<endl<<endl;
    //system("color 1");
    personal p;
    p.personal1();
    p.save(file);
    cout<<endl;
    cout<<endl;
    cout<<"Let's us know more about you and your family."<<endl<<endl;
    family *f=new family();
    f->quest();
    f->save(file);
    cout<<endl;
    cout<<endl;
    student *s1;
    working *w1;
    cout<<"Further, we would like to know about your work."<<endl<<endl;
    if(p.job1()==1)
    {student *s=new student();
    s1=s;
    s->save(file);}
    else if(p.job1()==2){working *w=new working();
    w1=w;
    w->save(file);}
    else{cout<<"";}
    cout<<endl<<endl;
    cout<<"Next, let's talk about your social life."<<endl<<endl;
    social_life *s2=new social_life();
    cout<<endl<<endl;
    fordelay(10000000000000);
    cout<<"Feeling Tired of answering questions?"<<endl;
    cout<<"No worries let me tell you a joke."<<endl;
    cout<<endl;
    cout<<"A pair of cows were talking in the field.\nOne says, 'Have you heard about the mad cow disease that's going around?' "<<endl ;
    fordelay(1000000000000000);
    cout<<"'Yeah,' the other cow says.\n'Makes me glad I'm a penguin.'"<<endl;
    cout<<endl<<endl;
    cout<<"Let's move on to your body health."<<endl<<endl;
    body_health *bl=new body_health();
    bl->save(file);
    cout<<endl<<endl;
    cout<<"Lastly and most importantly, let's talk about your mental health."<<endl<<endl;
    mental_health *mh=new mental_health();
    cout<<endl<<endl;
    cout<<"Congratulations!! "<<p.na()<<". You have answered all of the questions."<<endl;
    cout<<"Now, it's the time for you to know more about yourself deeply."<<endl;
    cout<<"Lets's see what our team has analysed about you."<<endl;
    cout<<endl;
    fordelay(1000000000000000);
    personal *p1=f;
    p1->analysis();
    cout<<endl;
    cout<<endl;
    fordelay(1000000000000000);
    if(p.job1()==1)
    {p1=s1;
    p1->analysis();}
    else if(p.job1()==2){p1=w1;
    p1->analysis();}
    else{cout<<"";}
    cout<<endl;
    cout<<endl;
    fordelay(1000000000000000);
    fordelay(1000000000000000);
    p1=s2;
    p1->analysis();
    cout<<endl;
    cout<<endl;
    fordelay(1000000000000000);
    p1=bl;
    p1->analysis();
    cout<<endl;
    cout<<endl;
    fordelay(1000000000000000);
    p1=mh;
    p1->analysis();
    cout<<endl;
    cout<<endl;
    fordelay(1000000000000000);
    fordelay(1000000000000000);
    cout<<"It was nice talking to you and knowing about you."<<endl;
    cout<<"Maybe our analysis helps you somewhere or the other."<<endl;
    cout<<"Thank you, for being with us."<<endl;
    cout<<"Please pay the consultation fees at the reception kiosk."<<endl;
    fordelay(1000000000000000);
    cout<<"Sorry, that was a joke."<<endl;
    cout<<"Have a nice day!!!!"<<endl;
    return 0;
}