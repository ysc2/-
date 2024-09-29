#include "lcd.h"
#include "string.h"
#include "delay.h"
#include "gui.h"

/******************************************************************************
      ����˵������ָ��λ�û���
      ������ݣ�x,y ��������
                color �����ɫ
      ����ֵ��  ��
******************************************************************************/
void GUI_DrawPoint(u16 x,u16 y,u16 color)
{
	LCD_Address_Set(x,y,x,y);//���ù��λ�� 
	LCD_WR_DATA(color);
} 
/******************************************************************************
      ����˵����8�Գ��Ի�Բ�㷨(�ڲ�����)
      ������ݣ�(xc,yc) :Բ��������
                (x,y):��������Բ�ĵ�����
                c �����ɫ
                
      ����ֵ��  ��
******************************************************************************/
void _draw_circle_8(int xc, int yc, int x, int y, u16 c)
{
	GUI_DrawPoint(xc + x, yc + y, c);

	GUI_DrawPoint(xc - x, yc + y, c);

	GUI_DrawPoint(xc + x, yc - y, c);

	GUI_DrawPoint(xc - x, yc - y, c);

	GUI_DrawPoint(xc + y, yc + x, c);

	GUI_DrawPoint(xc - y, yc + x, c);

	GUI_DrawPoint(xc + y, yc - x, c);

	GUI_DrawPoint(xc - y, yc - x, c);
}

/******************************************************************************
      ����˵������ָ��λ�û�һ��ָ����С��Բ
      ������ݣ�(xc,yc) :Բ��������
                c:������ɫ
                r:Բ�뾶
                fill:����жϱ�־��1-��䣬0-�����
      ����ֵ��  ��
******************************************************************************/
void gui_circle(int xc, int yc,u16 c,int r, int fill)
{
	int x = 0, y = r, yi, d;

	d = 3 - 2 * r;


	if (fill) 
	{
		// �����䣨��ʵ��Բ��
		while (x <= y) {
			for (yi = x; yi <= y; yi++)
				_draw_circle_8(xc, yc, x, yi, c);

			if (d < 0) {
				d = d + 4 * x + 6;
			} else {
				d = d + 4 * (x - y) + 10;
				y--;
			}
			x++;
		}
	} else 
	{
		// �������䣨������Բ��
		while (x <= y) {
			_draw_circle_8(xc, yc, x, y, c);
			if (d < 0) {
				d = d + 4 * x + 6;
			} else {
				d = d + 4 * (x - y) + 10;
				y--;
			}
			x++;
		}
	}
}

/******************************************************************************
      ����˵������ʾһ���ַ���,������Ӣ����ʾ
      ������ݣ�x,y :�������
                c:������ɫ
								fc:ǰ�û�����ɫ
								bc:������ɫ
								str :�ַ���	 
								size:�����С
								mode:ģʽ	0,���ģʽ;1,����ģʽ
      ����ֵ��  ��
******************************************************************************/  	   		   
void Show_Str(u16 x, u16 y,u8 *str,u16 fc, u16 bc,u8 sizey,u8 mode)
{					
	u16 x0=x;							  	  
  u8 bHz=0;     //�ַ��������� 
	while(*str!=0)//����δ����
	{ 
		if(!bHz)
		{
			if(x>(lcddev.width-sizey/2)||y>(lcddev.height-sizey)) return; 
			if(*str>0x80)bHz=1;//���� 
			else              //�ַ�
			{          
				if(*str==0x0D)//���з���
				{
					y+=sizey;
					x=x0;
					str++; 
				}else
				{
					LCD_ShowChar(x,y,*str,fc,bc,sizey,mode);
					x+=sizey/2; //�ַ�,Ϊȫ�ֵ�һ�� 
				} 
			  str++; 
			}
		}else//���� 
		{   
			if(x>(lcddev.width-sizey)||y>(lcddev.height-sizey)) return;  
			bHz=0;//�к��ֿ�    
			if(sizey==32)
				LCD_ShowChinese32x32(x,y,str,fc,bc,sizey,mode);	 	
			else if(sizey==24)
				LCD_ShowChinese24x24(x,y,str,fc,bc,sizey,mode);	
			else if(sizey==16)
			  LCD_ShowChinese16x16(x,y,str,fc,bc,sizey,mode);
			else 
			  LCD_ShowChinese12x12(x,y,str,fc,bc,sizey,mode);
				str+=2; 
				x+=sizey;//��һ������ƫ��	    
			}						 
	}   
}

/******************************************************************************
      ����˵����������ʾһ���ַ���,������Ӣ����ʾ
      ������ݣ�x,y :�������
                c:������ɫ
								fc:ǰ�û�����ɫ
								bc:������ɫ
								str :�ַ���	 
								size:�����С
								mode:ģʽ	0,���ģʽ;1,����ģʽ
      ����ֵ��  ��
******************************************************************************/  
void Gui_StrCenter(u16 x, u16 y,u8 *str,u16 fc,u16 bc,u8 sizey,u8 mode)
{
	u16 len=strlen((const char *)str);
	u16 x1=(lcddev.width-len*8)/2;
	Show_Str(x+x1,y,str,fc,bc,sizey,mode);
} 
