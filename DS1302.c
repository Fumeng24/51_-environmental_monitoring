#include "DS1302.h"

//void DS1302_delay(uchar dd)
//{
//    uchar i;
//    for(;dd>0;dd--)
//  for(i=110;i>0;i--);
//}
//void DS1302_init(uchar *time)
//{
//    DS1302_delay(2);
//	RST=0;			//RST���õ�
//	SCK=0;			//SCK���õ�
//    ds1302_write_byte(0x8e,0x00);
//    if(ds1302_read_byte(0X81)&0X80)
//    {
//        DS1302_SetTime(time);
//    }

//}
//DS1302��ʼ������
void ds1302_init(void) 
{
	RST=0;			//RST���õ�
	SCK=0;			//SCK���õ�
}
//��DS1302д��һ�ֽ�����
void ds1302_write_byte(uchar addr, uchar d) 
{
	uchar i;
	RST=1;					//����DS1302����	
	//д��Ŀ���ַ��addr
	addr = addr & 0xFE;   //���λ���㣬�Ĵ���0λΪ0ʱд��Ϊ1ʱ��
	for (i = 0; i < 8; i ++) {
		if (addr & 0x01) {
			IO=1;
			}
		else {
			IO=0;
			}
		SCK=1;      //����ʱ��
		SCK=0;
		addr = addr >> 1;
		}	
	//д�����ݣ�d
	for (i = 0; i < 8; i ++) {
		if (d & 0x01) {
			IO=1;
			}
		else {
			IO=0;
			}
		SCK=1;    //����ʱ��
		SCK=0;
		d = d >> 1;
		}
	RST=0;		//ֹͣDS1302����
}

//��DS1302����һ�ֽ�����
uchar ds1302_read_byte(uchar addr) {

	uchar i,temp,mm,nn,value;	
	RST=1;					//����DS1302����
	//д��Ŀ���ַ��addr
	addr = addr | 0x01;    //���λ�øߣ��Ĵ���0λΪ0ʱд��Ϊ1ʱ��
	for (i = 0; i < 8; i ++) {
		if (addr & 0x01) {
			IO=1;
			}
		else {
			IO=0;
			}
		SCK=1;
		SCK=0;
		addr = addr >> 1;
		}	
	//������ݣ�temp
	for (i = 0; i < 8; i ++) {
		temp = temp >> 1;
		if (IO) {
			temp |= 0x80;
			}
		else {
			temp &= 0x7F;
			}
		SCK=1;
		SCK=0;
		}	
	RST=0;					//ֹͣDS1302����
mm=temp/16;
nn=temp%16;
value=mm*10+nn;
return value;
}

void DS1302_SetTime(uchar *ad)
{
	ds1302_write_byte(0x8e,0x00);   //WP=0 ��������д��DS1302
/**********���¶�ʱ����ĳ�ʼ��*************/
    ds1302_write_byte(ds1302_sec_addr,ad[5]/10*16+ad[5]%10);  //��
    ds1302_write_byte(ds1302_min_addr,ad[4]/10*16+ad[4]%10);   //��
    ds1302_write_byte(ds1302_hour_addr,ad[3]/10*16+ad[3]%10);   //ʱ
/**********���¶������յĳ�ʼ��*************/
    ds1302_write_byte(ds1302_day_addr,ad[2]/10*16+ad[2]%10);
	ds1302_write_byte(ds1302_month_addr,ad[1]/10*16+ad[1]%10);
	ds1302_write_byte(ds1302_year_addr,ad[0]/10*16+ad[0]%10);
	ds1302_write_byte(0x8e,0x80);   //0x8e�����ֽڵ�ַ,bit7=WP WP=1 ��ֹ����д��DS1302
  }
//��DS302����ʱ������
void DS1302_Readtime(void)//
{
			time_data[0]=ds1302_read_byte( 0x8D);
			time_data[1]=ds1302_read_byte( 0x89);
			time_data[2]=ds1302_read_byte( 0x87);
			time_data[3]=ds1302_read_byte( 0x85);
			time_data[4]=ds1302_read_byte( 0x83);
			time_data[5]=ds1302_read_byte( 0x81);
}
/*****************************************
 * ???: void DS1302_OFF(void)
 * ??  :DS1302??????
 *  ??  :
 * ??  :
 * ??  :
 *************************************/
//  void DS1302_OFF(void)
//  {
//   uchar temp;
//   temp=ds1302_read_byte(0x81);//???????
//   ds1302_write_byte(0x8e,0x00);//WP=0 ??????DS1302
//   temp=temp|(1<<7);
//   ds1302_write_byte(0x80,temp);//WP=1 ??????DS1302

//  }
///*****************************************
// * ???: void DS1302_ON(void)
// * ??  :DS1302??????,??
// *  ??  :
// * ??  :
// * ??  :
// *************************************/
//  void DS1302_ON(void)
//  {
//   uchar temp;
//   temp=ds1302_read_byte(0x81);
//   ds1302_write_byte(0x8e,0x00);//WP=0 ??????DS1302
//   temp=temp|(0<<7);
//   ds1302_write_byte(0x80,temp);//WP=0 ??????DS1302

//  }



