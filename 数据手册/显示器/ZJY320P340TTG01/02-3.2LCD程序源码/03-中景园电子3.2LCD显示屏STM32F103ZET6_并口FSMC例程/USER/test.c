#include "lcd.h"
#include "delay.h"
#include "gui.h"
#include "test.h"
#include "touch.h"
#include "pic.h"

//========================variable==========================//
u16 ColorTab[5]={BRED,YELLOW,RED,GREEN,BLUE};//������ɫ����
//=====================end of variable======================//

/******************************************************************************
���ܣ�    ���Ʋ��Խ���
���������str :�ַ���ָ��
����ֵ��  ��
******************************************************************************/
void DrawTestPage(u8 *str)
{
//���ƹ̶���up
LCD_Fill(0,0,lcddev.width,20,BLUE);
//���ƹ̶���down
LCD_Fill(0,lcddev.height-20,lcddev.width,lcddev.height,BLUE);
Gui_StrCenter(0,2,str,WHITE,BLUE,16,1);//������ʾ
Gui_StrCenter(0,lcddev.height-18,"�о�԰��Ȩ���� ",WHITE,BLUE,16,1);//������ʾ
//���Ʋ�������
LCD_Fill(0,20,lcddev.width,lcddev.height-20,BLACK);
}

//******************************************************************
//��������  main_test
//���ܣ�    ����ȫ�������ۺϲ��Գ���������
//�����������
//����ֵ��  ��
//�޸ļ�¼��
//******************************************************************
void main_test(void)
{
	DrawTestPage("�о�԰�����ۺϲ��Գ���");
	
	Gui_StrCenter(0,30,"�о�԰����",RED,BLUE,16,1);//������ʾ
	Gui_StrCenter(0,60,"�ۺϲ��Գ���",RED,BLUE,16,1);//������ʾ	
	Gui_StrCenter(0,90,"ILI9341 240X320",RED,BLUE,16,1);//������ʾ
	Gui_StrCenter(0,120,"�о�԰���� 2020-05-05",RED,BLUE,16,1);//������ʾ
	delay_ms(1000);		
	delay_ms(1000);
}

//******************************************************************
//��������  Test_Color
//���ܣ�    ��ɫ�����ԣ���������ɫ����ɫ����ɫ����ɫ����ɫ
//�����������
//����ֵ��  ��
//�޸ļ�¼��
//******************************************************************
void Test_Color(void)
{
	DrawTestPage("����1:��ɫ������");
	LCD_Fill(0,20,lcddev.width,lcddev.height-20,WHITE);
	Show_Str(lcddev.width-50,30,"White",BLUE,YELLOW,16,1);delay_ms(500);
	LCD_Fill(0,20,lcddev.width,lcddev.height-20,BLACK);
	Show_Str(lcddev.width-50,30,"Black",BLUE,YELLOW,16,1);delay_ms(500);
	LCD_Fill(0,20,lcddev.width,lcddev.height-20,RED);
	Show_Str(lcddev.width-50,30,"Red",BLUE,YELLOW,16,1); delay_ms(500);
	LCD_Fill(0,20,lcddev.width,lcddev.height-20,GREEN);
	Show_Str(lcddev.width-50,30,"Green",BLUE,YELLOW,16,1);delay_ms(500);
	LCD_Fill(0,20,lcddev.width,lcddev.height-20,BLUE);
	Show_Str(lcddev.width-50,30,"Blue",BLUE,YELLOW,16,1);delay_ms(500);

}

//******************************************************************
//��������  Test_FillRec
//���ܣ�    ���ο���ʾ�������ԣ�������ʾ�ۺ�ɫ����ɫ����ɫ����ɫ����ɫ���ο�
//       	��ʱ1500��������ΰ��շۺ�ɫ����ɫ����ɫ����ɫ����ɫ�����ο� 
//�����������
//����ֵ��  ��
//�޸ļ�¼��
//******************************************************************
void Test_FillRec(void)
{
	u8 i=0;
	DrawTestPage("����2:GUI����������");
	LCD_Fill(0,20,lcddev.width,lcddev.height-20,WHITE);
	for (i=0; i<5; i++) 
	{
		LCD_DrawRectangle(lcddev.width/2-80+(i*15),lcddev.height/2-80+(i*15),lcddev.width/2-80+(i*15)+60,lcddev.height/2-80+(i*15)+60,ColorTab[i]); 
	}
	delay_ms(1500);	
	LCD_Fill(0,20,lcddev.width,lcddev.height-20,WHITE); 
	for (i=0; i<5; i++) 
	{
		LCD_Fill(lcddev.width/2-80+(i*15),lcddev.height/2-80+(i*15),lcddev.width/2-80+(i*15)+60,lcddev.height/2-80+(i*15)+60,ColorTab[i]); 
	}
	delay_ms(1500);
}

//******************************************************************
//��������  Test_FillRec
//���ܣ�    Բ�ο���ʾ�������ԣ�������ʾ�ۺ�ɫ����ɫ����ɫ����ɫ����ɫԲ�ο�
//       	��ʱ1500��������ΰ��շۺ�ɫ����ɫ����ɫ����ɫ����ɫ���Բ�ο� 
//�����������
//����ֵ��  ��
//�޸ļ�¼��
//******************************************************************
void Test_Circle(void)
{
	u8 i=0;
	DrawTestPage("����3:GUI��Բ������");
	LCD_Fill(0,20,lcddev.width,lcddev.height-20,WHITE);
	for (i=0; i<5; i++)  
		gui_circle(lcddev.width/2-80+(i*25),lcddev.height/2-50+(i*25),ColorTab[i],30,0);
	delay_ms(1500);	
	LCD_Fill(0,20,lcddev.width,lcddev.height-20,WHITE); 
	for (i=0; i<5; i++) 
	  	gui_circle(lcddev.width/2-80+(i*25),lcddev.height/2-50+(i*25),ColorTab[i],30,1);
	delay_ms(1500);
}

//******************************************************************
//��������  English_Font_test
//���ܣ�    Ӣ����ʾ���� 
//�����������
//����ֵ��  ��
//�޸ļ�¼��
//******************************************************************
void English_Font_test(void)
{
	DrawTestPage("����4:Ӣ����ʾ����");
	Show_Str(10,40,"8X16:abcdefghijklmnopqrstuvwxyz0123456789",RED,BLUE,16,0);
	Show_Str(10,70,"8X16:ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789",RED,BLUE,16,1);
	Show_Str(10,100,"8X16:~!@#$%^&*()_+{}:<>?/|-+.",RED,BLUE,16,0); 
	delay_ms(1200);
}

//******************************************************************
//��������  Chinese_Font_test
//���ܣ�    ������ʾ����
//�����������
//����ֵ��  ��
//�޸ļ�¼��
//******************************************************************
void Chinese_Font_test(void)
{	
	DrawTestPage("����5:������ʾ����");
	Show_Str(10,30,"16X16:�о�԰���Ӽ������޹�˾��ӭ��",BLUE,YELLOW,16,0);
	Show_Str(10,50,"16X16:Welcome�о�԰",BLUE,YELLOW,16,1);
	Show_Str(10,70,"24X24:Welcome�о�԰",BLUE,YELLOW,24,1);
	Show_Str(10,100,"32X32:Welcome�о�԰",BLUE,YELLOW,32,1);
	delay_ms(1200);
}

//******************************************************************
//��������  Pic_test
//���ܣ�    ͼƬ��ʾ���ԣ�������ʾ����40X40 QQͼ��
//�����������
//����ֵ��  ��
//�޸ļ�¼��
//******************************************************************
void Pic_test(void)
{
	DrawTestPage("����6:ͼƬ��ʾ����");
	LCD_Fill(0,20,lcddev.width,lcddev.height-20,WHITE);
	LCD_ShowPicture(30,30,40,40,gImage_1);
	Show_Str(30+12,75,"QQ",BLUE,YELLOW,16,1);
	LCD_ShowPicture(90,30,40,40,gImage_1);
	Show_Str(90+12,75,"QQ",BLUE,YELLOW,16,1);
	LCD_ShowPicture(150,30,40,40,gImage_1);
	Show_Str(150+12,75,"QQ",BLUE,YELLOW,16,1);
	delay_ms(1200);
}

//******************************************************************
//��������  Touch_Test
//���ܣ�    ������д����
//�����������
//����ֵ��  ��
//�޸ļ�¼��
//******************************************************************
void Touch_Test(void)
{
	u16 lastpos[2];//���һ�ε�����
	lastpos[0]=0xffff;
	TP_Init();//������ʼ��
	LCD_Clear(WHITE);
	DrawTestPage("����7:Touch����");
	while(1)
	{
		tp_dev.scan(0);//ɨ��
		if(tp_dev.sta&TP_PRES_DOWN)//�а���������
		{				  
			delay_ms(1);//��Ҫ����ʱ,��������Ϊ�а�������.		    
			if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)
			{			 
				if(lastpos[0]==0XFFFF)
				{
					lastpos[0]=tp_dev.x[0];
					lastpos[1]=tp_dev.y[0];
				}
				LCD_DrawRoughLine(lastpos[0],lastpos[1],tp_dev.x[0],tp_dev.y[0],RED);//����
				lastpos[0]=tp_dev.x[0];
				lastpos[1]=tp_dev.y[0];
				LCD_ShowString(10,lcddev.height-60,"X:",RED,BLACK,16,0);
				LCD_ShowIntNum(26,lcddev.height-60,tp_dev.x[0],3,RED,BLACK,16);
				LCD_ShowString(10,lcddev.height-40,"Y:",RED,BLACK,16,0);
				LCD_ShowIntNum(26,lcddev.height-40,tp_dev.y[0],3,RED,BLACK,16);
			}    
		}
  }
}




