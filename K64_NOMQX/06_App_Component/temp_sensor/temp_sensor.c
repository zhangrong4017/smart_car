//==========================================================================
//�ļ����ƣ�temp_sensor.c
//���ܸ�Ҫ���¶ȴ�����Ӧ����������Դ�ļ�
//==========================================================================

#include "temp_sensor.h"

//==========================================================================
//��������: temp_sensor_init
//��������: true: ��ʹ��У�Թ��ܣ���У�Թ������óɹ������߽�ֹУ�Թ���;
//         false:��ʹ��У�Թ��ܣ���У�Թ�������ʧ��;
//����˵��: ��
//���ܸ�Ҫ: ��ʼ���¶ȴ���������Ӧ������temp_sensor.h��
//��ע: ������ʱ��Ƶ��Ϊ48MHz��ʹ������ʱ��4��Ƶ�����16λת����Ӳ������8��������ֵ��
//     ������ʱ�����12��ADCK���ڣ�����ת��ʱ�������ʱ��ԼΪ31.02��s
//==========================================================================
bool temp_sensor_init() {
	//�������ó�ʼ��ADCģ��
	return adc_init(TEMP_SENSOR_ADC_MOD, TEMP_SENSOR_ADC_CLK_DIV,
	TEMP_SENSOR_ADC_ACCURACY, TEMP_SENSOR_ADC_HARDWARE_AVG,
	TEMP_SENSOR_ADC_ADLSTS, TEMP_SENSOR_ADC_ADHSC, TEMP_SENSOR_ADC_CAL);
}

//==========================================================================
//��������: temp_sensor_get
//��������: �¶ȴ����������¶ȣ���λ��C
//����˵��: ��
//���ܸ�Ҫ: ��ȡ�¶ȴ����������¶ȣ���λ��C
//��ע: ��ʹ�ò��9λת��ʱ���ֱ���ԼΪ7.99��C�����¶ȱ仯Լ7.99��Cʱ���ſ��Լ�����;
//     ��ʹ�ò��11λת��ʱ���ֱ���ԼΪ1.99��C;
//     ��ʹ�ò��13λת��ʱ���ֱ���ԼΪ0.50��C;
//     ��ʹ�ò��16λת��ʱ���ֱ���ԼΪ0.06��C;
//==========================================================================
float temp_sensor_get() {
	int16 ad;		//����ADֵ
	float vtemp;	//���ݲ���ADֵת�����ĵ�ѹֵ����λmV
	float temp;		//ʵ���¶ȣ���λ��C

	//��ȡ����ADֵ
	ad = adc_diff_get(TEMP_SENSOR_ADC_MOD, TEMP_SENSOR_ADC_DIFF_GROUP);
	//ת��Ϊ��ѹֵ
	vtemp = ad * TEMP_SENSOR_ADC_VTG * 1.0f
			/ ((1 << TEMP_SENSOR_ADC_DATA_BITS) - 1);
	//ת��Ϊ�¶�
	temp = 25 - ((vtemp - TEMP_SENSOR_VTEMP25) / TEMP_SENSOR_M);

	return temp;
}