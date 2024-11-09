#pragma once

#ifdef __linux__
// Linuxƽ̨��GT_API�Ķ���
#define GT_API extern "C" short
#else
// Windowsƽ̨��GT_API�Ķ���
#define GT_API extern "C" short __stdcall
#include "windows.h"
#endif

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
/*                        ��׼�������ܺ���		                          */
/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/

/*-----------------------------------------------------------*/
/* Channel of Command                                        */
/*-----------------------------------------------------------*/
#define CHANNEL_HOST                   (0)
#define CHANNEL_UART                   (1)
#define CHANNEL_SIM                    (2)
#define CHANNEL_ETHER                  (3)
#define CHANNEL_RS232                  (4)
#define CHANNEL_PCIE                   (5)
#define CHANNEL_RINGNET                (6)

/*-----------------------------------------------------------*/
/* Error Code                                                */
/*-----------------------------------------------------------*/
#define CMD_SUCCESS                     (0)

#define CMD_ERROR_READ_LEN              (-2)     /* ��ȡ���ݳ��ȴ��� */
#define CMD_ERROR_READ_CHECKSUM         (-3)     /* ��ȡ����У��ʹ��� */

#define CMD_ERROR_WRITE_BLOCK           (-4)     /* д�����ݿ���� */
#define CMD_ERROR_READ_BLOCK            (-5)     /* ��ȡ���ݿ���� */

#define CMD_ERROR_OPEN                  (-6)     /* ���豸���� */
#define CMD_ERROR_CLOSE                 (-6)     /* �ر��豸���� */
#define CMD_ERROR_DSP_BUSY              (-7)     /* DSPæ */

#define CMD_LOCK_ERROR                  (-8)     /* ���߳���Դæ */
#define CMD_DMA_ERROR                   (-9)     /* DMA������� */
#define CMD_COMM_ERROR                  (-10)    /* pcieͨѶʧ�� */
#define CMD_LOAD_RINGNET_DLL_ERROR      (-11)    /* �Ȼ��������ʧ�� */
#define CMD_RINGNET_STIME_ERROR         (-12)    /* �Ȼ��������ʧ�� */

#define CMD_RINGNET_ENC0_ERROR          (-13)    /* core1��������ʼ��ʧ�� */

#define CMD_RINGNET_ENC1_ERROR          (-14)    /* core2��������ʼ��ʧ�� */

#define CMD_LOAD_RINGNET_ERROR          (-17)    /* �Ȼ�����API����ʧ�� */
#define CMD_MCVERSION_MATCH_ERROR       (-15)    /* �Ȼ���ƥ��ʧ�ܣ���Ҫ���¿� */
#define CMD_LOCK_NULL                   (-20)    /* ���̱߳����򿪾��ʧ�� */
#define CMD_MCVERSION_MATCH_WARNING     (15)     /* �˿ذ汾ƥ��ʧ�ܣ�ĳЩ���ܲ��߱� */
#define CMD_DSPVERSION_MATCH_WARNING    (16)     /* �˿�DSP�汾����,���߱��汾ƥ�书�� */

#define CMD_FILE_MATCH_WARNING          (17)     /* �����ļ���ʽ�����ڲ�ƥ�� */

#define CMD_ERROR_EXECUTE               (1)
#define CMD_ERROR_VERSION_NOT_MATCH     (3)
#define CMD_ERROR_PARAMETER             (7)
#define CMD_ERROR_UNKNOWN               (8)      /* unspported command */

#define MC_NONE                         (-1)

#define MC_LIMIT_POSITIVE               (0)
#define MC_LIMIT_NEGATIVE               (1)
#define MC_ALARM                        (2)
#define MC_HOME                         (3)
#define MC_GPI                          (4)
#define MC_ARRIVE                       (5)
#define MC_EGPI0                        (6)
// #define MC_EGPI1                     (7)
// #define MC_EGPI2                     (8)
#define MC_MPG                          (9)

#define MC_ENABLE                       (10)
#define MC_CLEAR                        (11)
#define MC_GPO                          (12)
// #define MC_EGPO0                     (13)
// #define MC_EGPO1                     (14)
#define MC_AU_ADC                       (17)
#define MC_HSO                          (18)
#define MC_AU_DAC                       (19)


#define MC_DAC                          (20)
#define MC_STEP                         (21)
#define MC_PULSE                        (22)
#define MC_ENCODER                      (23)
#define MC_ADC                          (24)

#define MC_AU_ENCODER                   (26)

#define MC_ABS_ENCODER                  (29)

#define MC_AXIS                         (30)
#define MC_PROFILE                      (31)
#define MC_CONTROL                      (32)

#define MC_TRIGGER                      (40)

#define MC_AU_TRIGGER                   (44)

#define MC_TERMINAL                     (50)                                   // ��վģ��������Դ
#define MC_NET_PORT                     (51)
#define MC_AU_ENCODER_EX                (52)
#define MC_MPG_ENCODER                  (53)
#define MC_SERIAL_NUMBER                (55)                                   // ģ������к���Դ��ʶ
#define MC_SLOTS_NUMBER                 (56)                                   // ģ��֧�ֵĲ�����Ϣ��Դ��ʶ
#define MC_SUB_TERMINAL                 (57)                                   // ��վģ���Ӱ�������Դ
#define MC_EXT_MODULE                   (60)
#define MC_EXT_DI                       (61)
#define MC_EXT_DO                       (62)
#define MC_EXT_AI                       (63)
#define MC_EXT_AO                       (64)
#define MC_EHMI_DI                      (65)
#define MC_EHMI_DO                      (66)
#define MC_LOCAL_TERMINAL_NO_RESOURCE   (67)
#define MC_AXIS_CONNECT                 (68)

#define MC_SCAN_CRD                     (70)
#define MC_LASER                        (71)

#define MC_POS_COMPARE                  (80)

#define MC_WATCH_VAR                    (200)
#define MC_WATCH_EVENT                  (201)

typedef struct
{
	short year;
	short month;
	short day;
	short version;
	short user;
	short reserve1;
	short reserve2;
	short chip;
} TVersion;

#define CORE_MODE_TIMER                 (0)
#define CORE_MODE_SYNCH                 (1)
#define CORE_MODE_EXTERNAL              (2)

#define CORE_TASK_DEFAULT               (0)
#define CORE_TASK_DLM                   (1)

#define SKIP_MODULE_SCAN                (0x001)
#define SKIP_MODULE_POS_COMPARE         (0x002)
#define SKIP_MODULE_CRD                 (0x004)

#define SKIP_MODULE_PLC                 (0x010)
#define SKIP_MODULE_DLM                 (0x020)

#define SKIP_MODULE_AXIS_CALCULATE      (0x100)

#define SKIP_MODULE_WATCH               (0x800)

typedef enum
{
	TIME_ELAPSE_PROFILE = 1000,

	TIME_ELAPSE_INTERRUPT_ERROR_COUNT = 1100,

	TIME_ELAPSE_HOST_COMMAND_EXECUTE = 1220,
	TIME_ELAPSE_ETHER_COMMAND_EXECUTE,

	TIME_ELAPSE_PROFILE_CALCULATE = 6000,

	TIME_ELAPSE_SCAN = 18000,

	TIME_ELAPSE_AXIS_CHECK = 20000,
	TIME_ELAPSE_AXIS_CALCULATE,
	TIME_ELAPSE_AXIS_FILTER,

	TIME_ELAPSE_ENCODER = 30000,

	TIME_ELAPSE_DI = 31000,

	TIME_ELAPSE_DO = 32000,

	TIME_ELAPSE_AI = 33000,

	TIME_ELAPSE_AO = 34000,

	TIME_ELAPSE_TRIGGER = 38000,

	TIME_ELAPSE_CONTROL = 40000,

	TIME_ELAPSE_WATCH = 52000,

	TIME_ELAPSE_TERMINAL = 53000,

	TIME_ELAPSE_TERMINAL_OPERATION = 53001,

	TIME_ELAPSE_READ_ADC = 54000,

} ETimeElapse;

typedef struct Pid
{
	double kp;
	double ki;
	double kd;
	double kvff;
	double kaff;
	long   integralLimit;
	long   derivativeLimit;
	short  limit;
} TPid;

typedef struct
{
	short axisIndex[2];
	short reserve1[2];
	double radius;
	double center[2];
}TAxisCircularSafetyZone;

typedef struct
{
	short refType;           // ��ȫ���ο����ͣ�MC_ENCODER/MC_AU_ENCODER/MC_AU_ENCODER_EX/MC_MPG_ENCODER
	short refIndex;          // ��ȫ���ο����Ͷ�Ӧ��������
	short reserve1[2];
	double refRatio;         // �ο�������refRatio = (��1mm��Ӧ��������)/(�ο�����1mm��Ӧ��������)
	double limitPositive;    // ��ȫ������Χ����λ������
	double limitNegative;    // ��ȫ������Χ����λ������
}TProfileReferenceSafetyZone;

#define NET_INIT_MODE_AUTO                       (0)    // �Զ�ɨ�����磬Ĭ��ģʽ
#define NET_INIT_MODE_SKIP_TERMINAL              (1)    // ֧��ECAT xml�ļ���վģʽ��
#define NET_INIT_MODE_MULT_OPEN                  (2)    // ˫��ģʽ��

#define NET_INIT_MODE_MOTION_STUDIO              (99)   // GVNʱMotionStudio����ģʽ������ҪXML
#define NET_INIT_MODE_XML_STRICT                 (100)  // XML�ϸ񿪿�ģʽ

#define NO_NET                                   (0xf)
#define RING_NET                                 (6)
#define ETHERCAT_NET                             (8)
#define ETHERCAT_RING_MISC_NET                   (9)

#define NET_SRC_NONE                             (NO_NET)
#define NET_SRC_FROM_RING_NET                    (RING_NET)
#define NET_SRC_FROM_ECAT_NET                    (ETHERCAT_NET)

/*-----------------------------------------------------------*/
/* Basic function                                            */
/*-----------------------------------------------------------*/
GT_API GT_SetCardNo(short index);
GT_API GT_GetCardNo(short *pIndex);
GT_API GT_Open(short channel=0,short param=1);
GT_API GT_Close(void);
GT_API GT_SetCore(short core);
GT_API GT_GetCore(short *pCore);
GT_API GT_GetVersion(char **pVersion);
GT_API GT_GetVersionEx(short type,TVersion *pVersion);
GT_API GT_Reset();
GT_API GT_GetClock(unsigned long *pClock,unsigned long *pLoop=NULL);
GT_API GT_GetClockHighPrecision(unsigned long *pClock);
GT_API GT_ClearTime(ETimeElapse item);
GT_API GT_GetTime(ETimeElapse item,unsigned long *pTime,unsigned long *pTimeMax,unsigned long *pValue=NULL);
GT_API GT_GetSts(short axis,long *pSts,short count=1,unsigned long *pClock=NULL);
GT_API GT_ClrSts(short axis,short count=1);
GT_API GT_AxisOn(short axis);
GT_API GT_AxisOff(short axis);
GT_API GT_MultiAxisOn(unsigned long mask);
GT_API GT_MultiAxisOff(unsigned long mask);
GT_API GT_SetAxisOnDelayTime(unsigned short ms);
GT_API GT_GetAxisOnDelayTime(unsigned short *pMs);
GT_API GT_Stop(long mask,long option);
GT_API GT_SetPrfPos(short profile,long prfPos);
GT_API GT_SynchAxisPos(long mask);
GT_API GT_ZeroPos(short axis,short count=1);
GT_API GT_GetLimitStatus(short axis,short *pLimitPositive,short *pLimitNegative);
GT_API GT_SetSoftLimitMode(short axis,short mode);
GT_API GT_GetSoftLimitMode(short axis,short *pMode);
GT_API GT_SetSoftLimit(short axis,long positive,long negative);
GT_API GT_GetSoftLimit(short axis,long *pPositive,long *pNegative);
GT_API GT_SetAxisBand(short axis,long band,long time);
GT_API GT_GetAxisBand(short axis,long *pBand,long *pTime);
GT_API GT_GetPrfPos(short profile,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetPrfVel(short profile,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetPrfAcc(short profile,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetPrfMode(short profile,long *pValue, short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAxisPrfPos(short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAxisPrfPosCompensate(short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAxisPrfVel(short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAxisPrfAcc(short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAxisEncPos(short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAxisEncVel(short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAxisEncAcc(short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAxisError(short axis,double *pValue, short count=1,unsigned long *pClock=NULL);
GT_API GT_SetControlFilter(short control,short index);
GT_API GT_GetControlFilter(short control,short *pIndex);
GT_API GT_SetControlSuperimposed(short control,short superimposedType,short superimposedIndex);
GT_API GT_GetControlSuperimposed(short control,short *pSuperimposedType,short *pSuperimposedIndex);
GT_API GT_SetPid(short control,short index,TPid *pPid);
GT_API GT_GetPid(short control,short index,TPid *pPid);
GT_API GT_SetKvffFilter(short control,short index,short kvffFilterExp,double accMax);
GT_API GT_GetKvffFilter(short control,short index,short *pKvffFilterExp,double *pAccMax);
GT_API GT_Delay(unsigned short ms);
GT_API GT_DelayHighPrecision(unsigned short profile);

GT_API GTN_OpenCard(short channel=0,void *pPrm=NULL,char *pFileName=NULL);
GT_API GTN_NetInit(short mode=0,void *pPrm=NULL,short overTime=0,long *pStatus=NULL);

GT_API GTN_Open(short channel=5,short param=1);
GT_API GTN_OpenRingNet(short channel=5,short param=1,char *pFile=NULL,short index=1,long count=1);
GT_API GTN_Close(void);
GT_API GTN_GetChannel(short *pChannel);
GT_API GTN_GetVersion(short core,char **pVersion);
GT_API GTN_GetVersionEx(short core,short type,TVersion *pVersion);
GT_API GTN_SetVersion(short core,short type,TVersion *pVersion);
GT_API GTN_Reset(short core);
GT_API GTN_GetClock(short core,unsigned long *pClock,unsigned long *pLoop=NULL);
GT_API GTN_GetClockHighPrecision(short core,unsigned long *pClock);
GT_API GTN_ClearTime(short core,ETimeElapse item);
GT_API GTN_GetTime(short core,ETimeElapse item,unsigned long *pTime,unsigned long *pTimeMax,unsigned long *pValue=NULL);
GT_API GTN_SetCoreMode(short core,short mode);
GT_API GTN_GetCoreMode(short core,short *pMode);
GT_API GTN_SetCoreShare(short core,short type,short index,short count);
GT_API GTN_GetCoreShare(short core,short type,short *pIndex,short *pCount);
GT_API GTN_SetCoreTask(short core,short task);
GT_API GTN_GetCoreTask(short core,short *pTask);
GT_API GTN_GetResMax(short core,short type,short *pCount);
GT_API GTN_SetResCount(short core,short type,short count);
GT_API GTN_GetResCount(short core,short type,short *pCount);
GT_API GTN_GetSts(short core,short axis,long *pSts,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetPrfSts(short core,short profile,long *pSts,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetDriverSts(short core,short axis,long *pSts,short count=1,unsigned long *pClock=NULL);
GT_API GTN_ClrSts(short core,short axis,short count=1);
GT_API GTN_AxisOn(short core,short axis);
GT_API GTN_AxisOff(short core,short axis);
GT_API GTN_MultiAxisOn(short core,unsigned long mask);
GT_API GTN_MultiAxisOff(short core,unsigned long mask);
GT_API GTN_SetAxisOnDelayTime(short core,unsigned short delayTime);
GT_API GTN_GetAxisOnDelayTime(short core,unsigned short *pDelayTime);
GT_API GTN_Stop(short core,long mask,long option);
GT_API GTN_SetPrfPos(short core,short profile,long prfPos);
GT_API GTN_SynchAxisPos(short core,long mask);
GT_API GTN_ZeroPos(short core,short axis,short count=1);
GT_API GTN_GetLimitStatus(short core,short axis,short *pLimitPositive,short *pLimitNegative);
GT_API GTN_SetSoftLimitMode(short core,short axis,short mode);
GT_API GTN_GetSoftLimitMode(short core,short axis,short *pMode);
GT_API GTN_SetSoftLimit(short core,short axis,long positive,long negative);
GT_API GTN_GetSoftLimit(short core,short axis,long *pPositive,long *pNegative);
GT_API GTN_SetSoftLimitEx(short core,short axis,double positive,double negative);
GT_API GTN_GetSoftLimitEx(short core,short axis,double *pPositive,double *pNegative);
GT_API GTN_SetAxisBand(short core,short axis,long band,long time);
GT_API GTN_GetAxisBand(short core,short axis,long *pBand,long *pTime);
GT_API GTN_GetPrfPos(short core,short profile,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetPrfVel(short core,short profile,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetPrfAcc(short core,short profile,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetPrfMode(short core,short profile,long *pValue, short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAxisPrfPos(short core,short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAxisPrfPosCompensate(short core,short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAxisPrfVel(short core,short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAxisPrfAcc(short core,short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAxisEncPos(short core,short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAxisEncVel(short core,short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAxisEncAcc(short core,short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAxisError(short core,short axis,double *pValue, short count=1,unsigned long *pClock=NULL);
GT_API GTN_SetControlFilter(short core,short control,short index);
GT_API GTN_GetControlFilter(short core,short control,short *pIndex);
GT_API GTN_SetControlSuperimposed(short core,short control,short superimposedType,short superimposedIndex);
GT_API GTN_GetControlSuperimposed(short core,short control,short *pSuperimposedType,short *pSuperimposedIndex);
GT_API GTN_SetPid(short core,short control,short index,TPid *pPid);
GT_API GTN_GetPid(short core,short control,short index,TPid *pPid);
GT_API GTN_SetKvffFilter(short core,short control,short index,short kvffFilterExp,double accMax);
GT_API GTN_GetKvffFilter(short core,short control,short index,short *pKvffFilterExp,double *pAccMax);
GT_API GTN_Delay(short core,unsigned short ms);
GT_API GTN_DelayHighPrecision(short core,unsigned short profile);


#define STEP_DIR                        (0)
#define STEP_PULSE                      (1)
#define STEP_ORTHOGONAL                 (2)

GT_API GT_LoadConfig(char *pFile);
GT_API GT_AlarmOff(short axis);
GT_API GT_AlarmOn(short axis);
GT_API GT_LmtsOn(short axis,short limitType=-1);
GT_API GT_LmtsOff(short axis,short limitType=-1);
GT_API GT_StepDir(short step);
GT_API GT_StepPulse(short step);
GT_API GT_StepOrthogonal(short step);
GT_API GT_SetMtrBias(short dac,short bias);
GT_API GT_GetMtrBias(short dac,short *pBias);
GT_API GT_SetMtrLmt(short dac,short limit);
GT_API GT_GetMtrLmt(short dac,short *pLimit);
GT_API GT_EncOn(short encoder);
GT_API GT_EncOff(short encoder);
GT_API GT_SetPosErr(short control,long error);
GT_API GT_GetPosErr(short control,long *pError);
GT_API GT_SetStopDec(short profile,double decSmoothStop,double decAbruptStop);
GT_API GT_GetStopDec(short profile,double *pDecSmoothStop,double *pDecAbruptStop);
GT_API GT_CtrlMode(short axis,short mode);
GT_API GT_SetStopIo(short axis,short stopType,short inputType,short inputIndex);
GT_API GT_SetAdcFilterPrm(short adc,double k);
GT_API GT_GetAdcFilterPrm(short adc,double *pk);
GT_API GT_SetAxisPrfVelFilter(short axis,short filterNumExp);
GT_API GT_GetAxisPrfVelFilter(short axis,short *pFilterNumExp);
GT_API GT_SetAxisEncVelFilter(short axis,short filterNumExp);
GT_API GT_GetAxisEncVelFilter(short axis,short *pFilterNumExp);
GT_API GT_SetProfileScale(short i,long alpha,long beta);
GT_API GT_GetProfileScale(short i,long *pAlhpa,long *pBeta);
GT_API GT_SetEncoderScale(short i,long alpha,long beta);
GT_API GT_GetEncoderScale(short i,long *pAlhpa,long *pBeta);

GT_API GTN_LoadConfig(short core,char *pFile);
GT_API GTN_AlarmOn(short core,short axis);
GT_API GTN_AlarmOff(short core,short axis);
GT_API GTN_LmtsOn(short core,short axis,short limitType=-1);
GT_API GTN_LmtsOff(short core,short axis,short limitType=-1);
GT_API GTN_StepDir(short core,short step);
GT_API GTN_StepPulse(short core,short step);
GT_API GTN_StepOrthogonal(short core,short step);
GT_API GTN_SetMtrBias(short core,short dac,short bias);
GT_API GTN_GetMtrBias(short core,short dac,short *pBias);
GT_API GTN_SetMtrLmt(short core,short dac,short limit);
GT_API GTN_GetMtrLmt(short core,short dac,short *pLimit);
GT_API GTN_SetSense(short core,short dataType,short dataIndex,short value);
GT_API GTN_GetSense(short core,short dataType,short dataIndex,short *pValue);
GT_API GTN_EncOn(short core,short encoder);
GT_API GTN_EncOff(short core,short encoder);
GT_API GTN_SetPosErr(short core,short control,long error);
GT_API GTN_GetPosErr(short core,short control,long *pError);
GT_API GTN_SetAxisPosErrLimit(short core,short axis,long errorLimit);
GT_API GTN_GetAxisPosErrLimit(short core,short axis,long *pErrorLimit);
GT_API GTN_SetStopDec(short core,short profile,double decSmoothStop,double decAbruptStop);
GT_API GTN_GetStopDec(short core,short profile,double *pDecSmoothStop,double *pDecAbruptStop);
GT_API GTN_CtrlMode(short core,short axis,short mode);
GT_API GTN_SetStopIo(short core,short axis,short stopType,short inputType,short inputIndex);
GT_API GTN_SetAdcFilterPrm(short core,short adc,double k);
GT_API GTN_GetAdcFilterPrm(short core,short adc,double *pk);
GT_API GTN_SetAuAdcFilterPrm(short core,short adc,double k);
GT_API GTN_GetAuAdcFilterPrm(short core,short adc,double *pk);
GT_API GTN_SetAxisPrfVelFilter(short core,short axis,short filterNumExp);
GT_API GTN_GetAxisPrfVelFilter(short core,short axis,short *pFilterNumExp);
GT_API GTN_SetAxisEncVelFilter(short core,short axis,short filterNumExp);
GT_API GTN_GetAxisEncVelFilter(short core,short axis,short *pFilterNumExp);
GT_API GTN_SetProfileScale(short core,short i,long alpha,long beta);
GT_API GTN_GetProfileScale(short core,short i,long *pAlhpa,long *pBeta);
GT_API GTN_SetEncoderScale(short core,short i,long alpha,long beta);
GT_API GTN_GetEncoderScale(short core,short i,long *pAlhpa,long *pBeta);
GT_API GTN_SetAuEncoderScale(short core,short i,long alpha,long beta);
GT_API GTN_GetAuEncoderScale(short core,short i,long *pAlhpa,long *pBeta);

/*-----------------------------------------------------------*/
/* Capture and Triggr                                        */
/*-----------------------------------------------------------*/
#define CAPTURE_HOME                    (1)
#define CAPTURE_INDEX                   (2)
#define CAPTURE_PROBE                   (3)
#define CAPTURE_HSIO0                   (6)
#define CAPTURE_HSIO1                   (7)
#define CAPTURE_POSCOMPARE              (6)

typedef struct Trigger
{
	short encoder;
	short probeType;
	short probeIndex;
	short sense;
	long  offset;
	unsigned long loop;
	short windowOnly;
	long firstPosition;
	long lastPosition;
}TTrigger;

typedef struct TriggerEx
{
	short latchType;
	short latchIndex;
	short probeType;
	short probeIndex;
	short sense;
	long  offset;
	unsigned long loop;
	short windowOnly;
	long firstPosition;
	long lastPosition;
}TTriggerEx;

typedef struct TriggerAlign
{
	short encoder;
	short probeType;
	short probeIndex;
	short sense;
	long offset;
	unsigned long loop;
	short windowOnly;
	short pad2;
	long firstPosition;
	long lastPosition;
}TTriggerAlign;

typedef struct TriggerStatus
{
	short execute;
	short done;
	long position;
}TTriggerStatus;

typedef struct TriggerStatusEx
{
	short execute;
	short done;
	long position;
	unsigned long clock;
	unsigned long loopCount;
}TTriggerStatusEx;


GT_API GT_SetTrigger(short index,TTrigger *pTrigger);
GT_API GT_GetTrigger(short index,TTrigger *pTrigger);
GT_API GT_GetTriggerStatus(short index,TTriggerStatus *pTriggerStatus,short count=1);
GT_API GT_ClearTriggerStatus(short index);
GT_API GT_SetCaptureMode(short encoder,short mode);
GT_API GT_GetCaptureMode(short encoder,short *pMode,short count=1);
GT_API GT_GetCaptureStatus(short encoder,short *pStatus,long *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_SetCaptureSense(short encoder,short mode,short sense);
GT_API GT_ClearCaptureStatus(short encoder);
GT_API GT_SetCaptureRepeat(short encoder,short count);
GT_API GT_GetCaptureRepeatStatus(short encoder,short *pCount);
GT_API GT_GetCaptureRepeatPos(short encoder,long *pValue,short startNum,short count);
GT_API GT_SetCaptureRepeatFifoMode(short encoder,short mode);
GT_API GT_GetCaptureRepeatFifoMode(short encoder,short *pMode);


GT_API GTN_SetAuTrigger(short core,short index,TTriggerEx *pTrigger);
GT_API GTN_GetAuTrigger(short core,short index,TTriggerEx *pTrigger);
GT_API GTN_ClearAuTriggerStatus(short core,short index);
GT_API GTN_GetAuTriggerStatus(short core,short index,TTriggerStatusEx *pTriggerStatusEx,short count=1);


GT_API GTN_SetTrigger(short core,short index,TTrigger *pTrigger);
GT_API GTN_GetTrigger(short core,short index,TTrigger *pTrigger);
GT_API GTN_SetTriggerEx(short core,short index,TTriggerEx *pTrigger);
GT_API GTN_GetTriggerEx(short core,short index,TTriggerEx *pTrigger);
GT_API GTN_GetTriggerStatus(short core,short index,TTriggerStatus *pTriggerStatus,short count=1);
GT_API GTN_GetTriggerStatusEx(short core,short index,TTriggerStatusEx *pTriggerStatusEx,short count=1);
GT_API GTN_ClearTriggerStatus(short core,short index);
GT_API GTN_DisableTrigger(short core,short index);
GT_API GTN_SetCaptureMode(short core,short encoder,short mode);
GT_API GTN_GetCaptureMode(short core,short encoder,short *pMode,short count=1);
GT_API GTN_GetCaptureStatus(short core,short encoder,short *pStatus,long *pValue,short count,unsigned long *pClock);
GT_API GTN_SetCaptureSense(short core,short encoder,short mode,short sense);
GT_API GTN_ClearCaptureStatus(short core,short encoder);
GT_API GTN_SetCaptureRepeat(short core,short encoder,short count);
GT_API GTN_GetCaptureRepeatStatus(short core,short encoder,short *pCount);
GT_API GTN_GetCaptureRepeatPos(short core,short encoder,long *pValue,short startNum,short count);
GT_API GTN_SetCaptureRepeatFifoMode(short core,short encoder,short mode);
GT_API GTN_GetCaptureRepeatFifoMode(short core,short encoder,short *pMode);

typedef struct
{
	short fifoFull;
	short pad1[3];
	double pad2[2];
}TLatchValueInfo;

typedef struct TriggerPrm
{
	short latchType;
	short latchIndex;
	short probeType;
	short probeIndex;
	short sense;
	short loopType;
	long  offset;
	unsigned long loop;
	short windowOnly;
	short pad1;
	long firstPosition;
	long lastPosition;
	short fifoMode;
	short pad2[3];
	double pad3;
}TTriggerPrm;

typedef struct TriggerLatchPrm
{
	unsigned long latchIndex;//���񴥷���������š�
	long latchValue;//������ֵ����Trigger��������������й�	
	double   userValue;//�û����õ����ݣ���TTriggerPrm�Ĳ���pad3��Ӧ
	double   reserve;//��������������Ϊ0
}TTriggerLatchPrm;

#define LATCH_USER_VAR_DOUBLE           (100)
#define LATCH_USER_VAR_LONG              (101)

GT_API GTN_SetTriggerPrm(short core,short index,TTriggerPrm *pTriggerPrm);
GT_API GTN_GetTriggerPrm(short core,short index,TTriggerPrm *pTriggerPrm);
GT_API GTN_GetTriggerLatchValue(short core,short index,long count,long *pValue,long *pCount,TLatchValueInfo *pInfo);
GT_API GTN_GetTriggerLatchValuePro(short core,short index,long count,TTriggerLatchPrm *pLatchPrm,long *pCount,TLatchValueInfo *pInfo);
#define TRIGGER_DELTA_MODE_DEFAULT            (0)

#define TRIGGER_DELTA_CHECKPOINT_MODE_AUTO    (0)
#define TRIGGER_DELTA_CHECKPOINT_MODE_MANUAL  (1)

typedef struct Checkpoint
{
	short mode;
	long offset;
	short fifoIndex;
	unsigned long crossCount;
	short fifoDataCount;
	short dataReady;
	long data;
	short dataIndex;
} TCheckpoint;

typedef struct TriggerDeltaPrm
{
	short mode;
	short dir;
	short triggerIndex[2];
} TTriggerDeltaPrm;

typedef struct TriggerDelta
{
	short enable;
	short checkpointCount;
	short fifoDataCount;
	short lostCount;
}TTriggerDeltaInfo;

GT_API GT_ClearTriggerDelta(short index,short mode=0);
GT_API GT_AddTriggerDeltaCheckpoint(short index,short mode,long offset,short fifo=0,short *pIndex=NULL);
GT_API GT_ReadTriggerDeltaCheckpointData(short index,short checkpointIndex,long *pBuf,short count,short *pReadCount);
GT_API GT_WriteTriggerDeltaCheckpointData(short index,short checkpointIndex,long *pBuf,short count,short *pWriteCount);
GT_API GT_SetTriggerDeltaPrm(short index,TTriggerDeltaPrm *pPrm);
GT_API GT_GetTriggerDeltaPrm(short index,TTriggerDeltaPrm *pPrm);
GT_API GT_GetTriggerDeltaCheckpoint(short index,short checkpointIndex,TCheckpoint *pCheckpoint);
GT_API GT_GetTriggerDeltaInfo(short index,TTriggerDeltaInfo *pTriggerDelta);
GT_API GT_TriggerDeltaOn(short index);
GT_API GT_TriggerDeltaOff(short index);

GT_API GTN_ClearTriggerDelta(short core,short index,short mode=0);
GT_API GTN_AddTriggerDeltaCheckpoint(short core,short index,short mode,long offset,short fifo=0,short *pIndex=NULL);
GT_API GTN_ReadTriggerDeltaCheckpointData(short core,short index,short checkpointIndex,long *pBuf,short count,short *pReadCount);
GT_API GTN_WriteTriggerDeltaCheckpointData(short core,short index,short checkpointIndex,long *pBuf,short count,short *pWriteCount);
GT_API GTN_SetTriggerDeltaPrm(short core,short index,TTriggerDeltaPrm *pPrm);
GT_API GTN_GetTriggerDeltaPrm(short core,short index,TTriggerDeltaPrm *pPrm);
GT_API GTN_GetTriggerDeltaCheckpoint(short core,short index,short checkpointIndex,TCheckpoint *pCheckpoint);
GT_API GTN_GetTriggerDeltaInfo(short core,short index,TTriggerDeltaInfo *pTriggerDelta);
GT_API GTN_TriggerDeltaOn(short core,short index);
GT_API GTN_TriggerDeltaOff(short core,short index);

GT_API GT_LinkCaptureOffset(short encoder,short source);
GT_API GT_SetCaptureOffset(short encoder,long *pOffset,short count,long loop);
GT_API GT_GetCaptureOffset(short encoder,long *pOffset,short *pCount,long *pLoop);
GT_API GT_GetCaptureOffsetStatus(short encoder,short *pCount,long *pLoop,long *pCapturePos);

GT_API GT_SetCaptureEncoder(short trigger,short encoder);
GT_API GT_GetCaptureWidth(short trigger,short *pWidth,short count);

GT_API GTN_LinkCaptureOffset(short core,short encoder,short source);
GT_API GTN_SetCaptureOffset(short core,short encoder,long *pOffset,short count,long loop);
GT_API GTN_GetCaptureOffset(short core,short encoder,long *pOffset,short *pCount,long *pLoop);
GT_API GTN_GetCaptureOffsetStatus(short core,short encoder,short *pCount,long *pLoop,long *pCapturePos);

/*-----------------------------------------------------------*/
/* Basic Motion                                              */
/*-----------------------------------------------------------*/
typedef struct TrapPrm
{
	double acc;
	double dec;
	double velStart;
	short  smoothTime;
} TTrapPrm;

GT_API GT_Update(long mask);
GT_API GT_SetPos(short profile,long pos);
GT_API GT_GetPos(short profile,long *pPos);
GT_API GT_SetVel(short profile,double vel);
GT_API GT_GetVel(short profile,double *pVel);

GT_API GT_PrfTrap(short profile);
GT_API GT_SetTrapPrm(short profile,TTrapPrm *pPrm);
GT_API GT_GetTrapPrm(short profile,TTrapPrm *pPrm);

GT_API GTN_Update(short core,long mask);
GT_API GTN_SetPos(short core,short profile,long pos);
GT_API GTN_GetPos(short core,short profile,long *pPos);
GT_API GTN_SetVel(short core,short profile,double vel);
GT_API GTN_GetVel(short core,short profile,double *pVel);

GT_API GTN_PrfTrap(short core,short profile);
GT_API GTN_SetTrapPrm(short core,short profile,TTrapPrm *pPrm);
GT_API GTN_GetTrapPrm(short core,short profile,TTrapPrm *pPrm);

typedef struct JogPrm
{
	double acc;
	double dec;
	double smooth;
} TJogPrm;

GT_API GT_PrfJog(short profile);
GT_API GT_SetJogPrm(short profile,TJogPrm *pPrm);
GT_API GT_GetJogPrm(short profile,TJogPrm *pPrm);

GT_API GTN_PrfJog(short core,short profile);
GT_API GTN_SetJogPrm(short core,short profile,TJogPrm *pPrm);
GT_API GTN_GetJogPrm(short core,short profile,TJogPrm *pPrm);

#define PT_MODE_STATIC                  (0)
#define PT_MODE_DYNAMIC                 (1)

#define PT_SEGMENT_NORMAL               (0)
#define PT_SEGMENT_EVEN                 (1)
#define PT_SEGMENT_STOP                 (2)

typedef struct
{
	double prfPos;
	long loop;
	short mode;
	short fifoUse;
	short fifoPlace;
	short segmentNumber;
	unsigned long segmentReceive[2];
	unsigned long segmentExecute[2];
	unsigned long bufferReceive[2];
	unsigned long bufferExecute[2];
} TPtInfo;

GT_API GT_PrfPt(short profile,short mode=PT_MODE_STATIC);
GT_API GT_SetPtLoop(short profile,long loop);
GT_API GT_GetPtLoop(short profile,long *pLoop);
GT_API GT_PtSpace(short profile,short *pSpace,short fifo=0);
GT_API GT_PtSpaceEx(short profile,short *pSpace,short *pListSpace,short fifo=0);
GT_API GT_PtData(short profile,double pos,long time,short type=PT_SEGMENT_NORMAL,short fifo=0);
GT_API GT_PtClear(short profile,short fifo=0);
GT_API GT_PtStart(long mask,long option=0);
GT_API GT_SetPtMemory(short profile,short memory);
GT_API GT_GetPtMemory(short profile,short *pMemory);
GT_API GT_SetPtPrecisionMode(short profile,short precisionMode);
GT_API GT_GetPtPrecisionMode(short profile,short *pPrecisionMode);
GT_API GT_GetPtInfo(short profile,TPtInfo *pPtInfo);
GT_API GT_SetPtLink(short profile,short fifo,short list);
GT_API GT_GetPtLink(short profile,short fifo,short *pList);
GT_API GT_PtDoBit(short profile,short doType,short index,short value,short fifo=0);
GT_API GT_PtAo(short profile,short aoType,short index,double value,short fifo=0);
//GT_API GTN_PosCurrFeedForward(short core,short profile,double pos,long time,short torque,short type,short fifo=0);

GT_API GTN_PrfPt(short core,short profile,short mode=PT_MODE_STATIC);
GT_API GTN_SetPtLoop(short core,short profile,long loop);
GT_API GTN_GetPtLoop(short core,short profile,long *pLoop);
GT_API GTN_PtSpace(short core,short profile,short *pSpace,short fifo=0);
GT_API GTN_PtSpaceEx(short core,short profile,short *pSpace,short *pListSpace,short fifo=0);
GT_API GTN_PtData(short core,short profile,double pos,long time,short type=PT_SEGMENT_NORMAL,short fifo=0);
GT_API GTN_PtClear(short core,short profile,short fifo=0);
GT_API GTN_PtStart(short core,long mask,long option=0);
GT_API GTN_SetPtMemory(short core,short profile,short memory);
GT_API GTN_GetPtMemory(short core,short profile,short *pMemory);
GT_API GTN_SetPtPrecisionMode(short core,short profile,short precisionMode);
GT_API GTN_GetPtPrecisionMode(short core,short profile,short *pPrecisionMode);
GT_API GTN_GetPtInfo(short core,short profile,TPtInfo *pPtInfo);
GT_API GTN_SetPtLink(short core,short profile,short fifo,short list);
GT_API GTN_GetPtLink(short core,short profile,short fifo,short *pList);
GT_API GTN_PtDoBit(short core,short profile,short doType,short index,short value,short fifo=0);
GT_API GTN_PtAo(short core,short profile,short aoType,short index,double value,short fifo=0);


typedef struct TPvtTableMovePrm
{
	short tableId;
	long distance;
	double vm;
	double am;
	double jm;
	double time;
} TPvtTableMovePrm;

GT_API GT_PrfPvt(short profile);
GT_API GT_SetPvtLoop(short profile,long loop);
GT_API GT_GetPvtLoop(short profile,long *pLoopCount,long *pLoop);
GT_API GT_PvtStatus(short profile,short *pTableId,double *pTime,short count=1);
GT_API GT_PvtStart(long mask);
GT_API GT_PvtTableSelect(short profile,short tableId);

GT_API GT_PvtTable(short tableId,long count,double *pTime,double *pPos,double *pVel);
GT_API GT_PvtTableEx(short tableId,long count,double *pTime,double *pPos,double *pVelBegin,double *pVelEnd);
GT_API GT_PvtTableComplete(short tableId,long count,double *pTime,double *pPos,double *pA,double *pB,double *pC,double velBegin=0,double velEnd=0);
GT_API GT_PvtTablePercent(short tableId,long count,double *pTime,double *pPos,double *pPercent,double velBegin=0);
GT_API GT_PvtPercentCalculate(long n,double *pTime,double *pPos,double *pPercent,double velBegin,double *pVel);
GT_API GT_PvtTableContinuous(short tableId,long count,double *pPos,double *pVel,double *pPercent,double *pVelMax,double *pAcc,double *pDec,double timeBegin);
GT_API GT_PvtTableContinuousEx(short tableId,long n,double *pPos,double *pVel,double *pAccPercent,double *pDecPercent,double *pVelMax,double *pAcc,double *pDec,double timeBegin);
GT_API GT_PvtContinuousCalculate(long n,double *pPos,double *pVel,double *pPercent,double *pVelMax,double *pAcc,double *pDec,double *pTime);

GT_API GT_PvtTableMove(short tableId,long distance,double vm,double am,double jm,double *pTime=NULL);
GT_API GT_PvtTableMove2(short tableId,long distance,double vm,double am,double jm,double *pTime=NULL);
GT_API GT_PvtTableMovePercent(short tableId,long distance,double vm,
							  double acc,double pa1,double pa2,
							  double dec,double pd1,double pd2,
							  double *pVel=NULL,double *pAcc=NULL,double *pDec=NULL,double *pTime=NULL);
GT_API GT_PvtTableMovePercentEx(short tableId,long distance,double vm,
								double acc,double pa1,double pa2,double ma,
								double dec,double pd1,double pd2,double md,
								double *pVel=NULL,double *pAcc=NULL,double *pDec=NULL,double *pTime=NULL);

GT_API GT_PvtTableMoveTogether(short tableCount,TPvtTableMovePrm *pPvtTableMovePrm);

GT_API GTN_PrfPvt(short core,short profile);
GT_API GTN_SetPvtLoop(short core,short profile,long loop);
GT_API GTN_GetPvtLoop(short core,short profile,long *pLoopCount,long *pLoop);
GT_API GTN_PvtStatus(short core,short profile,short *pTableId,double *pTime,short count=1);
GT_API GTN_PvtStart(short core,long mask);
GT_API GTN_PvtTableSelect(short core,short profile,short tableId);

GT_API GTN_PvtTable(short core,short tableId,long count,double *pTime,double *pPos,double *pVel);
GT_API GTN_PvtTableEx(short core,short tableId,long count,double *pTime,double *pPos,double *pVelBegin,double *pVelEnd);
GT_API GTN_PvtTableComplete(short core,short tableId,long count,double *pTime,double *pPos,double *pA,double *pB,double *pC,double velBegin=0,double velEnd=0);
GT_API GTN_PvtTablePercent(short core,short tableId,long count,double *pTime,double *pPos,double *pPercent,double velBegin=0);
GT_API GTN_PvtPercentCalculate(short core,long n,double *pTime,double *pPos,double *pPercent,double velBegin,double *pVel);
GT_API GTN_PvtTableContinuous(short core,short tableId,long count,double *pPos,double *pVel,double *pPercent,double *pVelMax,double *pAcc,double *pDec,double timeBegin);
GT_API GTN_PvtContinuousCalculate(short core,long n,double *pPos,double *pVel,double *pPercent,double *pVelMax,double *pAcc,double *pDec,double *pTime);

GT_API GTN_PvtTableMove(short core,short tableId,long distance,double vm,double am,double jm,double *pTime=NULL);
GT_API GTN_PvtTableMove2(short core,short tableId,long distance,double vm,double am,double jm,double *pTime=NULL);
GT_API GTN_PvtTableMovePercent(short core,short tableId,long distance,double vm,
							   double acc,double pa1,double pa2,
							   double dec,double pd1,double pd2,
							   double *pVel=NULL,double *pAcc=NULL,double *pDec=NULL,double *pTime=NULL);
GT_API GTN_PvtTableMovePercentEx(short core,short tableId,long distance,double vm,
								 double acc,double pa1,double pa2,double ma,
								 double dec,double pd1,double pd2,double md,
								 double *pVel=NULL,double *pAcc=NULL,double *pDec=NULL,double *pTime=NULL);

GT_API GTN_PvtTableMoveTogether(short core,short tableCount,TPvtTableMovePrm *pPvtTableMovePrm);


#define GEAR_MASTER_ENCODER             (1)
#define GEAR_MASTER_PROFILE             (2)
#define GEAR_MASTER_AXIS                (3)
#define GEAR_MASTER_AU_ENCODER          (4)
#define GEAR_MASTER_MPG_ENCODER					(5)

#define GEAR_MASTER_ENCODER_OTHER       (101)
#define GEAR_MASTER_AXIS_OTHER          (103)
#define GEAR_MASTER_AU_ENCODER_OTHER		(104)
#define GEAR_MASTER_MPG_ENCODER_OTHER		(105)

#define GEAR_EVENT_START                (1)
#define GEAR_EVENT_PASS                 (2)
#define GEAR_EVENT_AREA                 (5)

GT_API GT_PrfGear(short profile,short dir=0);
GT_API GT_SetGearMaster(short profile,short masterIndex,short masterType=GEAR_MASTER_PROFILE,short masterItem=0);
GT_API GT_GetGearMaster(short profile,short *pMasterIndex,short *pMasterType=NULL,short *pMasterItem=NULL);
GT_API GT_SetGearRatio(short profile,long masterEven,long slaveEven,long masterSlope=0);
GT_API GT_GetGearRatio(short profile,long *pMasterEven,long *pSlaveEven,long *pMasterSlope=NULL);
GT_API GT_GearStart(long mask);
GT_API GT_SetGearEvent(short profile,short event,long startPara0,long startPara1);
GT_API GT_GetGearEvent(short profile,short *pEvent,long *pStartPara0,long *pStartPara1);

GT_API GTN_PrfGear(short core,short profile,short dir=0);
GT_API GTN_SetGearMaster(short core,short profile,short masterIndex,short masterType=GEAR_MASTER_PROFILE,short masterItem=0);
GT_API GTN_GetGearMaster(short core,short profile,short *pMasterIndex,short *pMasterType=NULL,short *pMasterItem=NULL);
GT_API GTN_SetGearRatio(short core,short profile,long masterEven,long slaveEven,long masterSlope=0);
GT_API GTN_GetGearRatio(short core,short profile,long *pMasterEven,long *pSlaveEven,long *pMasterSlope=NULL);
GT_API GTN_GearStart(short core,long mask);
GT_API GTN_SetGearEvent(short core,short profile,short event,long startPara0,long startPara1);
GT_API GTN_GetGearEvent(short core,short profile,short *pEvent,long *pStartPara0,long *pStartPara1);

typedef struct{
	unsigned short masterIndex;        // GearInģʽ�������������
	short masterValueSource;           // ����Դ
	short pad1;                        // ����ֵ��������0
	short pad2;                        // ����ֵ��������0
	long ratioNumerator;               // ���ֱȵķ���
	unsigned long ratioDenominator;    // ���ֱȵķ�ĸ
	double acceleration;               // ������ļ��ٶ�
	double deceleration;               // ������ļ��ٶ�
	double jerk;                       // ������ļӼ��ٶ�
	double pad3;                       // ����ֵ��������0
}TGearInParameter;

typedef struct  
{
	short state;
	unsigned short masterIndex;        // GearInģʽ�������������
	unsigned short masterValueSource;  // ����Դ
	short pad1[3];                     // ����ֵ��������0

	long ratioNumerator;               // ���ֱȵķ���
	unsigned long ratioDenominator;    // ���ֱȵķ�ĸ
	long slaveEven;                    // ���Թ�Լ����ĳ��ֱȵķ���
	unsigned long masterEven;          // ���Թ�Լ����ĳ��ֱȵķ�ĸ
	double acceleration;               // ������ļ��ٶ�
	double deceleration;               // ������ļ��ٶ�
	double jerk;                       // ������ļӼ��ٶ�
	double pad2;                       // ����ֵ��������0
}TGearInInfo;

GT_API GTN_SetGearInParameter(short core, short slaveIndex, TGearInParameter *pGearInPrm);
GT_API GTN_GearInStart(short core, unsigned long *pStartMask, unsigned short maskCount);
GT_API GTN_GetGearInInfo(short core, unsigned short slaveIndex, TGearInInfo *pGearInInfo);

#define FOLLOW_SWITCH_SEGMENT			(1)
#define FOLLOW_SWITCH_TABLE				(2)

#define FOLLOW_MASTER_ENCODER           (1)
#define FOLLOW_MASTER_PROFILE           (2)
#define FOLLOW_MASTER_AXIS              (3)
#define FOLLOW_MASTER_AU_ENCODER        (4)

#define FOLLOW_MASTER_ENCODER_OTHER     (101)
#define FOLLOW_MASTER_AXIS_OTHER        (103)

#define FOLLOW_EVENT_START              (1)
#define FOLLOW_EVENT_PASS               (2)

#define FOLLOW_SEGMENT_NORMAL           (0)
#define FOLLOW_SEGMENT_EVEN             (1)
#define FOLLOW_SEGMENT_STOP             (2)
#define FOLLOW_SEGMENT_CONTINUE         (3)

GT_API GT_PrfFollow(short profile,short dir=0);
GT_API GT_SetFollowMaster(short profile,short masterIndex,short masterType=FOLLOW_MASTER_PROFILE,short masterItem=0);
GT_API GT_GetFollowMaster(short profile,short *pMasterIndex,short *pMasterType=NULL,short *pMasterItem=NULL);
GT_API GT_SetFollowLoop(short profile,long loop);
GT_API GT_GetFollowLoop(short profile,long *pLoop);
GT_API GT_SetFollowEvent(short profile,short event,short masterDir,long pos=0);
GT_API GT_GetFollowEvent(short profile,short *pEvent,short *pMasterDir,long *pPos=NULL);
GT_API GT_FollowSpace(short profile,short *pSpace,short fifo=0);
GT_API GT_FollowData(short profile,long masterSegment,double slaveSegment,short type=FOLLOW_SEGMENT_NORMAL,short fifo=0);
GT_API GT_FollowClear(short profile,short fifo=0);
GT_API GT_FollowStart(long mask,long option=0);
GT_API GT_FollowSwitch(long mask);
GT_API GT_SetFollowMemory(short profile,short memory);
GT_API GT_GetFollowMemory(short profile,short *pMemory);
GT_API GT_GetFollowStatus(short profile,short *pFifoNum,short *pSwitchStatus);
GT_API GT_SetFollowPhasing(short profile,short profilePhasing);
GT_API GT_GetFollowPhasing(short profile,short *pProfilePhasing);

GT_API GT_PrfFollowEx(short profile,short dir=0);
GT_API GT_SetFollowMasterEx(short profile,short masterIndex,short masterType=FOLLOW_MASTER_PROFILE,short masterItem=0);
GT_API GT_GetFollowMasterEx(short profile,short *pMasterIndex,short *pMasterType=NULL,short *pMasterItem=NULL);
GT_API GT_SetFollowLoopEx(short profile,long loop);
GT_API GT_GetFollowLoopEx(short profile,long *pLoop);
GT_API GT_SetFollowEventEx(short profile,short event,short masterDir,long pos=0);
GT_API GT_GetFollowEventEx(short profile,short *pEvent,short *pMasterDir,long *pPos=NULL);
GT_API GT_FollowSpaceEx(short profile,short *pSpace,short fifo=0);
GT_API GT_FollowDataPercentEx(short profile,double masterSegment,double slaveSegment,short type=FOLLOW_SEGMENT_NORMAL,short percent=0,short fifo=0);
GT_API GT_FollowClearEx(short profile,short fifo=0);
GT_API GT_FollowStartEx(long mask,long option=0);
GT_API GT_FollowSwitchEx(long mask);
GT_API GT_SetFollowMemoryEx(short profile,short memory);
GT_API GT_GetFollowMemoryEx(short profile,short *pMemory);
GT_API GT_GetFollowStatusEx(short profile,short *pFifoNum,short *pSwitchStatus);
GT_API GT_SetFollowPhasingEx(short profile,short profilePhasing);
GT_API GT_GetFollowPhasingEx(short profile,short *pProfilePhasing);
GT_API GT_FollowSwitchNowEx(short profile,short method,short buffer=0,short fifo=0);
GT_API GT_FollowDataPercent2Ex(short profile,double masterSegment,double slaveSegment,double velBeginRatio,double velEndRatio,short percent=100,short *pPercent1=NULL,short fifo=0);
GT_API GT_GetFollowDataPercent2Ex(double masterPos,double v1,double v2,double p,double p1,double *pSlavePos);
GT_API GT_FollowDoBitEx(short profile,short doType,short index,short value,short fifo=0);
GT_API GT_FollowDelayEx(short profile,unsigned long delayTime,short fifo=0);
GT_API GT_FollowDiBitEx(short profile,short diType,short index,short value,unsigned long time=0,short fifo=0);

GT_API GTN_PrfFollow(short core,short profile,short dir=0);
GT_API GTN_SetFollowMaster(short core,short profile,short masterIndex,short masterType=FOLLOW_MASTER_PROFILE,short masterItem=0);
GT_API GTN_GetFollowMaster(short core,short profile,short *pMasterIndex,short *pMasterType=NULL,short *pMasterItem=NULL);
GT_API GTN_SetFollowLoop(short core,short profile,long loop);
GT_API GTN_GetFollowLoop(short core,short profile,long *pLoop);
GT_API GTN_SetFollowEvent(short core,short profile,short event,short masterDir,long pos=0);
GT_API GTN_GetFollowEvent(short core,short profile,short *pEvent,short *pMasterDir,long *pPos=NULL);
GT_API GTN_FollowSpace(short core,short profile,short *pSpace,short fifo=0);
GT_API GTN_FollowData(short core,short profile,long masterSegment,double slaveSegment,short type=FOLLOW_SEGMENT_NORMAL,short fifo=0);
GT_API GTN_FollowClear(short core,short profile,short fifo=0);
GT_API GTN_FollowStart(short core,long mask,long option=0);
GT_API GTN_FollowSwitch(short core,long mask);
GT_API GTN_SetFollowMemory(short core,short profile,short memory);
GT_API GTN_GetFollowMemory(short core,short profile,short *pMemory);
GT_API GTN_GetFollowStatus(short core,short profile,short *pFifoNum,short *pSwitchStatus);
GT_API GTN_SetFollowPhasing(short core,short profile,short profilePhasing);
GT_API GTN_GetFollowPhasing(short core,short profile,short *pProfilePhasing);

GT_API GTN_PrfFollowEx(short core,short profile,short dir=0);
GT_API GTN_SetFollowMasterEx(short core,short profile,short masterIndex,short masterType=FOLLOW_MASTER_PROFILE,short masterItem=0);
GT_API GTN_GetFollowMasterEx(short core,short profile,short *pMasterIndex,short *pMasterType=NULL,short *pMasterItem=NULL);
GT_API GTN_SetFollowLoopEx(short core,short profile,long loop);
GT_API GTN_GetFollowLoopEx(short core,short profile,long *pLoop);
GT_API GTN_SetFollowEventEx(short core,short profile,short event,short masterDir,long pos=0);
GT_API GTN_GetFollowEventEx(short core,short profile,short *pEvent,short *pMasterDir,long *pPos=NULL);
GT_API GTN_FollowSpaceEx(short core,short profile,short *pSpace,short fifo=0);
GT_API GTN_FollowDataPercentEx(short core,short profile,double masterSegment,double slaveSegment,short type=FOLLOW_SEGMENT_NORMAL,short percent=0,short fifo=0);
GT_API GTN_FollowClearEx(short core,short profile,short fifo=0);
GT_API GTN_FollowStartEx(short core,long mask,long option=0);
GT_API GTN_FollowSwitchEx(short core,long mask);
GT_API GTN_SetFollowMemoryEx(short core,short profile,short memory);
GT_API GTN_GetFollowMemoryEx(short core,short profile,short *pMemory);
GT_API GTN_GetFollowStatusEx(short core,short profile,short *pFifoNum,short *pSwitchStatus);
GT_API GTN_SetFollowPhasingEx(short core,short profile,short profilePhasing);
GT_API GTN_GetFollowPhasingEx(short core,short profile,short *pProfilePhasing);
GT_API GTN_FollowSwitchNowEx(short core,short profile,short method,short buffer=0,short fifo=0);
GT_API GTN_FollowDataPercent2Ex(short core,short profile,double masterSegment,double slaveSegment,double velBeginRatio,double velEndRatio,short percent=100,short *pPercent1=NULL,short fifo=0);
GT_API GTN_GetFollowDataPercent2Ex(short core,double masterPos,double v1,double v2,double p,double p1,double *pSlavePos);
GT_API GTN_FollowDoBitEx(short core,short profile,short doType,short index,short value,short fifo=0);
GT_API GTN_FollowDelayEx(short core,short profile,unsigned long delayTime,short fifo=0);
GT_API GTN_FollowDiBitEx(short core,short profile,short diType,short index,short value,unsigned long time=0,short fifo=0);

GT_API GT_SetFollowVirtualSeg(short profile,short segment,short axis,short fifo);
GT_API GT_GetFollowVirtualSeg(short profile,short *pSegment,short *pAxis,short fifo);

GT_API GT_GetFollowVirtualErr(short profile,double *pVirtualErr);
GT_API GT_ClearFollowVirtualErr(short profile);

typedef struct
{
	long pos;
	double vel;
	double acc;
	double dec;
	short percent;
} TMoveAbsolutePrm;

GT_API GT_MoveAbsolute(short profile,TMoveAbsolutePrm *pPrm);
GT_API GT_GetMoveAbsolute(short profile,TMoveAbsolutePrm *pPrm);

GT_API GTN_MoveAbsolute(short core,short profile,TMoveAbsolutePrm *pPrm);
GT_API GTN_GetMoveAbsolute(short core,short profile,TMoveAbsolutePrm *pPrm);

typedef struct
{
	short source;
	short enable;
	short x;
	short y;
	double theta;		// degree
} TTransformOrthogonal;

GT_API GT_SetTransformOrthogonal(short index,TTransformOrthogonal *pOrthogonal);
GT_API GT_GetTransformOrthogonal(short index,TTransformOrthogonal *pOrthogonal);
GT_API GT_GetTransformOrthogonalPosition(short index,double *pPositionX,double *pPositionY);

GT_API GTN_SetTransformOrthogonal(short core,short index,TTransformOrthogonal *pOrthogonal);
GT_API GTN_GetTransformOrthogonal(short core,short index,TTransformOrthogonal *pOrthogonal);
GT_API GTN_GetTransformOrthogonalPosition(short core,short index,double *pPositionX,double *pPositionY);


/*-----------------------------------------------------------*/
/* Comp                                                      */
/*-----------------------------------------------------------*/

#define COMP_TYPE_COORD_SYNC	(0)

typedef struct
{
	double translateion[2];	//��������ϵ���ԭʼ����ϵ��ƽ��
	double theta;	//��������ϵ���ԭʼ����ϵ����ת
}TCoordTransformPrm;

typedef struct
{
	short enable;	//�Ƿ�ʹ������ϵת������
	short refType;	//�ο����ͣ���������ΪMC_CRD��MC_GROUP��MC_PROFILE��
	short index;	//����ο�����ΪMC_CRD��д������ϵ��
	short refIndex[2];	//�ο���ţ�ָ������ϵ�е�ĳ�����ᣬ����profile��������
	double offset[2];	//������X2��Y2�����Բο�����ϵX1��Y1����ƫ��
	TCoordTransformPrm refTrans;	//�ο���������ϵ���ԭ����ϵ��ƽ�ƺ���ת
	TCoordTransformPrm syncTrans;	//ͬ����������ϵ���ԭ����ϵ��ƽ�ƺ���ת
	short reserve1[4];
	double reserve2[4];
}TCoordSyncCompPrm;

typedef struct
{
	short type;	//�������ͣ�����ͬ��������
	short index;	//һ������������ͬ������֧�����������������ϵ����������ʾ�ڼ���ͬ������
	short subIndex;	//���������������һ��ͬ�������ĵ�һ����
	short reserve1[5];
	double reserve2[4];
}TPrfComp;

GT_API GTN_PrfComp(short core,short profile,TPrfComp *pComp);
GT_API GTN_PrfCompEnable(short core,short profile,short enable,short enableType = 0);
GT_API GTN_BufPrfCompEnable(short core,short crd,short fifo,short profile,short enable,short enableType = 0);
GT_API GTN_SetCoordSyncCompPrm(short core,short index,TCoordSyncCompPrm *pPrm);
GT_API GTN_GetCoordSyncCompPrm(short core,short index,TCoordSyncCompPrm *pPrm);
GT_API GTN_GetCoordSyncCompValue(short core,short index,double x,double y,double *pCompX,double *pCompY);

/*-----------------------------------------------------------*/
/* Home                                                      */
/*-----------------------------------------------------------*/
#define HOME_STAGE_IDLE                           (0)
#define HOME_STAGE_START                          (1)
#define HOME_STAGE_ON_HOME_LIMIT_ESCAPE           (2)
#define HOME_STAGE_ON_HOME_ESCAPE                 (3)

#define HOME_STAGE_SEARCH_LIMIT                   (10)
#define HOME_STAGE_SEARCH_LIMIT_STOP              (11)

#define HOME_STAGE_SEARCH_LIMIT_ESCAPE            (13)

#define HOME_STAGE_SEARCH_LIMIT_RETURN            (15)
#define HOME_STAGE_SEARCH_LIMIT_RETURN_STOP       (16)

#define HOME_STAGE_SEARCH_HOME                    (20)

#define HOME_STAGE_SERCH_HOME_STOP                (22)
#define HOME_STAGE_SEARCH_HOME_OPPOSITE           (23)
#define HOME_STAGE_SEARCH_HOME_AGAIN              (24)
#define HOME_STAGE_SEARCH_HOME_RETURN             (25)

#define HOME_STAGE_SEARCH_INDEX                   (30)

#define HOME_STAGE_SEARCH_GPI                     (40)

#define HOME_STAGE_SEARCH_GPI_RETURN              (45)

#define HOME_STAGE_GO_HOME                        (80)

#define HOME_STAGE_END                            (100)

#define HOME_ERROR_NONE                           (0)
#define HOME_ERROR_NOT_TRAP_MODE                  (1)
#define HOME_ERROR_DISABLE                        (2)
#define HOME_ERROR_ALARM                          (3)
#define HOME_ERROR_STOP                           (4)
#define HOME_ERROR_STAGE                          (5)
#define HOME_ERROR_HOME_MODE                      (6)
#define HOME_ERROR_SET_CAPTURE_HOME               (7)
#define HOME_ERROR_NO_HOME                        (8)
#define HOME_ERROR_SET_CAPTURE_INDEX              (9)
#define HOME_ERROR_NO_INDEX                       (10)
#define HOME_ERROR_LIMIT                          (11)
#define HOME_ERROR_ESCAPE                         (12)

#define HOME_MODE_LIMIT                           (10)
#define HOME_MODE_LIMIT_HOME                      (11)
#define HOME_MODE_LIMIT_INDEX                     (12)
#define HOME_MODE_LIMIT_HOME_INDEX                (13)

#define HOME_MODE_HOME                            (20)

#define HOME_MODE_HOME_INDEX                      (22)

#define HOME_MODE_HOME_LEVEL                      (24)                               // ʹ��HOME��ƽ����(������û��HOME����������)

#define HOME_MODE_INDEX                           (30)
#define HOME_MODE_DRIVER_HOME                     (42)
#define HOME_MODE_FORCED_HOME                     (50)
#define HOME_MODE_FORCED_HOME_INDEX               (51)
typedef struct
{
	short mode;
	short moveDir;
	short indexDir;
	short edge;
	short triggerIndex;
	short pad1[3];
	double velHigh;
	double velLow;
	double acc;
	double dec;
	short smoothTime;
	short pad2[3];
	long homeOffset;
	long searchHomeDistance;
	long searchIndexDistance;
	long escapeStep;
	long pad3[2];
} THomePrm;

typedef struct
{
	short run;
	short stage;
	short error;
	short pad1;
	long capturePos;
	long targetPos;
} THomeStatus;

GT_API GT_GoHome(short axis,THomePrm *pHomePrm);
GT_API GT_GetHomePrm(short profile,THomePrm *pHomePrm);
GT_API GT_GetHomeStatus(short profile,THomeStatus *pHomeStatus);

GT_API GTN_GoHome(short core,short axis,THomePrm *pHomePrm);
GT_API GTN_GetHomePrm(short core,short axis,THomePrm *pHomePrm);
GT_API GTN_GetHomeStatus(short core,short axis,THomeStatus *pHomeStatus);

GT_API GT_HandwheelInit(short mode=0);
GT_API GT_SetHandwheelStopDec(short slave,double decSmoothStop,double decAbruptStop);
GT_API GT_StartHandwheel(short slave,short master,short masterEven,short slaveEven,short intervalTime,double acc,double dec,double vel,short stopWaitTime);
GT_API GT_EndHandwheel(short slave);

GT_API GTN_HandwheelInit(short core,short mode=0);
GT_API GTN_SetHandwheelStopDec(short core,short slave,double decSmoothStop,double decAbruptStop);
GT_API GTN_StartHandwheel(short core,short slave,short master,short masterEven,short slaveEven,short intervalTime,double acc,double dec,double vel,short stopWaitTime);
GT_API GTN_EndHandwheel(short core,short slave);

/*-----------------------------------------------------------*/
/* PLC                                                       */
/*-----------------------------------------------------------*/
#define PLC_THREAD_MAX					(32)
#define PLC_PAGE_MAX					(32)
#define PLC_LOCAL_VAR_MAX				(1024)
#define PLC_ACCESS_VAR_COUNT_MAX        (8)

#define PLC_TIMER_TT					(0)
#define PLC_TIMER_TF					(1)
#define PLC_TIMER_TTF					(2)

#define PLC_COUNTER_EQ					(0)
#define PLC_COUNTER_LE					(1)
#define PLC_COUNTER_GE					(2)

#define PLC_COUNTER_EDGE_UP				(0)
#define PLC_COUNTER_EDGE_DOWN			(1)
#define PLC_COUNTER_EDGE_UP_DOWN		(2)

#define PLC_FLANK_UP					(0)
#define PLC_FLANK_DOWN					(1)
#define PLC_FLANK_UP_DOWN				(2)

typedef enum
{
	PLC_BIND_NONE,
	PLC_BIND_DI,
	PLC_BIND_DO,
	PLC_BIND_TIMER,
	PLC_BIND_COUNTER,
	PLC_BIND_FLANK,
	PLC_BIND_SRFF,
} EPlcBind;

typedef struct VarInfo
{
	short id;
	short dataType;
	char  name[32];
} TVarInfo;

typedef struct
{
	short diType;
	short index;
	short reverse;
} TBindDi;

typedef struct
{
	short doType;
	short index;
	short reverse;
} TBindDo;

typedef struct
{
	short timerType;
	long delay;
	short inputVarId;
} TBindTimer;

typedef struct
{
	short counterType;
	short edge;
	long init;
	long target;
	long begin;
	long end;
	short dir;
	long unit;
	short inputVarId;
	short resetVarId;
} TBindCounter;

typedef struct
{
	short flankType;
	short inputVarId;
} TBindFlank;

typedef struct
{
	short setVarId;
	short resetVarId;
} TBindSrff;

typedef struct CompileInfo
{
	char  *pFileName;
	short *pLineNo;
	char  *pMessage;
} TCompileInfo;

typedef struct ThreadSts
{
	short  run;
	short  error;
	double result;
	short  line;
} TThreadSts;

GT_API GT_Compile(char *pFileName,TCompileInfo *pWrongInfo);
GT_API GT_Download(char *pFileName);
GT_API GT_GetFunId(char *pFunName,short *pFunId);
GT_API GT_GetVarId(char *pFunName,char *pVarName,TVarInfo *pVarInfo);
GT_API GT_Bind(short thread,short funId,short page);
GT_API GT_RunThread(short thread);
GT_API GT_RunThreadPeriod(short thread,short ms,short priority=4);
GT_API GT_StopThread(short thread);
GT_API GT_PauseThread(short thread);
GT_API GT_GetThreadSts(short thread,TThreadSts *pThreadSts);
GT_API GT_GetThreadTime(short thread,short *pPeriod,double *pExecuteTime,double *pExecuteTimeMax);
GT_API GT_SetVarValue(short page,TVarInfo *pVarInfo,double *pValue,short count=1);
GT_API GT_GetVarValue(short page,TVarInfo *pVarInfo,double *pValue,short count=1);

GT_API GT_UnbindVar(short thread);
GT_API GT_BindDi(short thread,TVarInfo *pVarInfo,TBindDi *pBindDi);
GT_API GT_BindDo(short thread,TVarInfo *pVarInfo,TBindDo *pBindDo);
GT_API GT_BindTimer(short thread,TVarInfo *pVarInfo,TBindTimer *pBindTimer);
GT_API GT_BindCounter(short thread,TVarInfo *pVarInfo,TBindCounter *pBindCounter);
GT_API GT_BindFlank(short thread,TVarInfo *pVarInfo,TBindFlank *pBindFlank);
GT_API GT_BindSrff(short thread,TVarInfo *pVarInfo,TBindSrff *pBindSrff);

GT_API GT_GetBindDi(TVarInfo *pVarInfo,TBindDi *pBindDi);
GT_API GT_GetBindDo(TVarInfo *pVarInfo,TBindDo *pBindDo);
GT_API GT_GetBindTimer(TVarInfo *pVarInfo,TBindTimer *pBindTimer,long *pCount);
GT_API GT_GetBindCounter(TVarInfo *pVarInfo,TBindCounter *pBindCounter,long *pUnitCount,long *pCount);
GT_API GT_GetBindFlank(TVarInfo *pVarInfo,TBindFlank *pBindFlank);
GT_API GT_GetBindSrff(TVarInfo *pVarInfo,TBindSrff *pBindSrff);

GT_API GTN_Compile(char *pFileName,TCompileInfo *pWrongInfo);
GT_API GTN_Download(short core,char *pFileName);
GT_API GTN_GetFunId(char *pFunName,short *pFunId);
GT_API GTN_GetVarId(char *pFunName,char *pVarName,TVarInfo *pVarInfo);
GT_API GTN_Bind(short core,short thread,short funId,short page);
GT_API GTN_RunThread(short core,short thread);
GT_API GTN_RunThreadPeriod(short core,short thread,short ms,short priority=4);
GT_API GTN_StepThread(short core,short thread);
GT_API GTN_StopThread(short core,short thread);
GT_API GTN_PauseThread(short core,short thread);
GT_API GTN_GetThreadSts(short core,short thread,TThreadSts *pThreadSts);
GT_API GTN_GetThreadTime(short core,short thread,short *pPeriod,double *pExecuteTime,double *pExecuteTimeMax);
GT_API GTN_SetVarValue(short core,short page,TVarInfo *pVarInfo,double *pValue,short count=1);
GT_API GTN_GetVarValue(short core,short page,TVarInfo *pVarInfo,double *pValue,short count=1);

GT_API GTN_UnbindVar(short core,short thread);
GT_API GTN_BindDi(short core,short thread,TVarInfo *pVarInfo,TBindDi *pBindDi);
GT_API GTN_BindDo(short core,short thread,TVarInfo *pVarInfo,TBindDo *pBindDo);
GT_API GTN_BindTimer(short core,short thread,TVarInfo *pVarInfo,TBindTimer *pBindTimer);
GT_API GTN_BindCounter(short core,short thread,TVarInfo *pVarInfo,TBindCounter *pBindCounter);
GT_API GTN_BindFlank(short core,short thread,TVarInfo *pVarInfo,TBindFlank *pBindFlank);
GT_API GTN_BindSrff(short core,short thread,TVarInfo *pVarInfo,TBindSrff *pBindSrff);

GT_API GTN_GetBindDi(short core,TVarInfo *pVarInfo,TBindDi *pBindDi);
GT_API GTN_GetBindDo(short core,TVarInfo *pVarInfo,TBindDo *pBindDo);
GT_API GTN_GetBindTimer(short core,TVarInfo *pVarInfo,TBindTimer *pBindTimer,long *pCount);
GT_API GTN_GetBindCounter(short core,TVarInfo *pVarInfo,TBindCounter *pBindCounter,long *pUnitCount,long *pCount);
GT_API GTN_GetBindFlank(short core,TVarInfo *pVarInfo,TBindFlank *pBindFlank);
GT_API GTN_GetBindSrff(short core,TVarInfo *pVarInfo,TBindSrff *pBindSrff);

GT_API GTN_GetBindDiCount(short core,short thread,short *pCount);
GT_API GTN_GetBindDoCount(short core,short thread,short *pCount);
GT_API GTN_GetBindTimerCount(short core,short thread,short *pCount);
GT_API GTN_GetBindCounterCount(short core,short thread,short *pCount);
GT_API GTN_GetBindFlankCount(short core,short thread,short *pCount);
GT_API GTN_GetBindSrffCount(short core,short thread,short *pCount);

GT_API GTN_GetBindDiInfo(short core,short thread,short index,short *pVar,TBindDi *pBindDi);
GT_API GTN_GetBindDoInfo(short core,short thread,short index,short *pVar,TBindDo *pBindDo);
GT_API GTN_GetBindTimerInfo(short core,short thread,short index,short *pVar,TBindTimer *pBindTimer);
GT_API GTN_GetBindCounterInfo(short core,short thread,short index,short *pVar,TBindCounter *pBindCounter);
GT_API GTN_GetBindFlankInfo(short core,short thread,short index,short *pVar,TBindFlank *pBindFlank);
GT_API GTN_GetBindSrffInfo(short core,short thread,short index,short *pVar,TBindSrff *pBindSrff);

typedef struct ThreadStatus
{
	short link;
	unsigned long  address;
	short size;
	unsigned long  page;
	short delay;
	short priority;
	short ptr;
	short status;
	short error;
	short result[4];
	short resultType;
	short breakpoint;
	short period;
	short count;
	short function;
} TThreadStatus;

GT_API GT_ClearPlc(void);
GT_API GT_LoadPlc(short id,short returnType);
GT_API GT_LoadPlcCommand(short id,short count,short *pData);
GT_API GT_StepThread(short thread);
GT_API GT_RunThreadToBreakpoint(short thread,short line);
GT_API GT_GetThread(short thread,TThreadStatus *pThread);


/*-----------------------------------------------------------*/
/* Interpolation                                             */
/*-----------------------------------------------------------*/
#define INTERPOLATION_AXIS_MAX                   (8)

#define CRD_OPERATION_DATA_EXT_MAX               (2)


#define CRD_BUFFER_MODE_DYNAMIC_DEFAULT          (0)
#define CRD_BUFFER_MODE_DYNAMIC_KEEP             (1)

#define CRD_BUFFER_MODE_STATIC_INPUT             (11)
#define CRD_BUFFER_MODE_STATIC_READY             (12)
#define CRD_BUFFER_MODE_STATIC_START             (13)

#define INTERPOLATION_CIRCLE_PLAT_XY             (0)
#define INTERPOLATION_CIRCLE_PLAT_YZ             (1)
#define INTERPOLATION_CIRCLE_PLAT_ZX             (2)

#define INTERPOLATION_HELIX_CIRCLE_XY_LINE_Z     (0)
#define INTERPOLATION_HELIX_CIRCLE_YZ_LINE_X     (1)
#define INTERPOLATION_HELIX_CIRCLE_ZX_LINE_Y     (2)

#define INTERPOLATION_CIRCLE_DIR_CW              (0)
#define INTERPOLATION_CIRCLE_DIR_CCW             (1)

typedef struct CrdPrm
{
	short dimension;
	short profile[8];
	double synVelMax;
	double synAccMax;
	short evenTime;
	short setOriginFlag;
	long originPos[8];
}TCrdPrm;

typedef struct CrdBufOperation
{
	short flag;
	unsigned short delay;
	short doType;
	unsigned short doMask;
	unsigned short doValue;
	unsigned short dataExt[CRD_OPERATION_DATA_EXT_MAX];
}TCrdBufOperation;

typedef struct CrdData
{
	short motionType;
	short circlePlat;
	long pos[INTERPOLATION_AXIS_MAX];
	double radius;
	short circleDir;
	double center[3];
	double vel;
	double acc;
	short velEndZero;
	TCrdBufOperation operation;

	double cos[INTERPOLATION_AXIS_MAX];
	double velEnd;
	double velEndAdjust;
	double r;
}TCrdData;

typedef struct
{
	double time;
	long segmentUsed;
	long segmentHead;
	long segmentTail;
} TCrdTime;

typedef struct
{
	short crdAxis;
	short masterIndex;
	short masterType;
} TBufFollowMaster;

typedef struct
{
	long masterPos;
	long pad;
} TBufFollowEventCross;

typedef struct
{
	short triggerIndex;
	long triggerOffset;
	long pad;
} TBufFollowEventTrigger;

typedef struct
{
	double velRatioMax;
	double accRatioMax;
	long masterLead;
	long masterEven;
	long slaveEven;
	short dir;
	short smoothPercent;
	short synchAlign;
} TCrdFollowPrm;

typedef struct
{
	short stage;
	double slavePos;
	double slaveVel;
	long masterFrameWidth;
	long masterFrameIndex;
	unsigned long loopCount;
} TCrdFollowStatus;

GT_API GT_SetCrdPrm(short crd,TCrdPrm *pCrdPrm);
GT_API GT_GetCrdPrm(short crd,TCrdPrm *pCrdPrm);
GT_API GT_CrdSpace(short crd,long *pSpace,short fifo=0);
GT_API GT_CrdData(short crd,TCrdData *pCrdData,short fifo=0);

GT_API GT_LnXY(short crd,long x,long y,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYOverride2(short crd,long x,long y,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYWN(short crd,long x,long y,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_LnXYOverride2WN(short crd,long x,long y,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_LnXYG0(short crd,long x,long y,double synVel,double synAcc,short fifo=0);
GT_API GT_LnXYG0Override2(short crd,long x,long y,double synVel,double synAcc,short fifo=0);
GT_API GT_LnXYG0WN(short crd,long x,long y,double synVel,double synAcc,long segNum=0,short fifo=0);
GT_API GT_LnXYG0Override2WN(short crd,long x,long y,double synVel,double synAcc,long segNum=0,short fifo=0);


GT_API GT_LnXYZ(short crd,long x,long y,long z,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYZOverride2(short crd,long x,long y,long z,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYZWN(short crd,long x,long y,long z,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_LnXYZOverride2WN(short crd,long x,long y,long z,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_LnXYZG0(short crd,long x,long y,long z,double synVel,double synAcc,short fifo=0);
GT_API GT_LnXYZG0Override2(short crd,long x,long y,long z,double synVel,double synAcc,short fifo=0);
GT_API GT_LnXYZG0WN(short crd,long x,long y,long z,double synVel,double synAcc,long segNum=0,short fifo=0);
GT_API GT_LnXYZG0Override2WN(short crd,long x,long y,long z,double synVel,double synAcc,long segNum=0,short fifo=0);

GT_API GT_LnXYZA(short crd,long x,long y,long z,long a,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYZAOverride2(short crd,long x,long y,long z,long a,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYZAWN(short crd,long x,long y,long z,long a,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_LnXYZAOverride2WN(short crd,long x,long y,long z,long a,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_LnXYZAG0(short crd,long x,long y,long z,long a,double synVel,double synAcc,short fifo=0);
GT_API GT_LnXYZAG0Override2(short crd,long x,long y,long z,long a,double synVel,double synAcc,short fifo=0);
GT_API GT_LnXYZAG0WN(short crd,long x,long y,long z,long a,double synVel,double synAcc,long segNum=0,short fifo=0);
GT_API GT_LnXYZAG0Override2WN(short crd,long x,long y,long z,long a,double synVel,double synAcc,long segNum=0,short fifo=0);

GT_API GT_LnXYZACUVW(short crd,long *pPos,short posMask,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYZACUVWWN(short crd,long *pPos,short posMask,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_LnXYZACUVWOverride2(short crd,long *pPos,short posMask,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYZACUVWOverride2WN(short crd,long *pPos,short posMask,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_ArcXYR(short crd,long x,long y,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcXYROverride2(short crd,long x,long y,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcXYRWN(short crd,long x,long y,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcXYROverride2WN(short crd,long x,long y,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_ArcXYC(short crd,long x,long y,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcXYCOverride2(short crd,long x,long y,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcXYCWN(short crd,long x,long y,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcXYCOverride2WN(short crd,long x,long y,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_ArcYZR(short crd,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcYZROverride2(short crd,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcYZRWN(short crd,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcYZROverride2WN(short crd,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_ArcYZC(short crd,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcYZCOverride2(short crd,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcYZCWN(short crd,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcYZCOverride2WN(short crd,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_ArcZXR(short crd,long z,long x,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcZXROverride2(short crd,long z,long x,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcZXRWN(short crd,long z,long x,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcZXROverride2WN(short crd,long z,long x,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_ArcZXC(short crd,long z,long x,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcZXCOverride2(short crd,long z,long x,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcZXCWN(short crd,long z,long x,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcZXCOverride2WN(short crd,long z,long x,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);


GT_API GT_ArcXYZ(short crd,long x,long y,long z,double interX,double interY,double interZ,double synVel,double synAcc,double velEnd,short fifo=0);
GT_API GT_ArcXYZWN(short crd,long x,long y,long z,double interX,double interY,double interZ,double synVel,double synAcc,double velEnd,long segNum,short fifo=0);
GT_API GT_ArcXYZOverride2WN(short crd,long x,long y,long z,double interX,double interY,double interZ,double synVel,double synAcc,double velEnd,long segNum,short fifo=0);


GT_API GT_HelixXYRZ(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd,short fifo=0);
GT_API GT_HelixXYRZOverride2(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixXYRZWN(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixXYRZOverride2WN(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_HelixXYCZ(short crd,long x,long y,long z,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixXYCZOverride2(short crd,long x,long y,long z,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixXYCZWN(short crd,long x,long y,long z,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixXYCZOverride2WN(short crd,long x,long y,long z,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_HelixYZRX(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixYZRXOverride2(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixYZRXWN(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixYZRXOverride2WN(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_HelixYZCX(short crd,long x,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixYZCXOverride2(short crd,long x,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixYZCXWN(short crd,long x,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixYZCXOverride2WN(short crd,long x,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_HelixZXRY(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixZXRYOverride2(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixZXRYWN(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixZXRYOverride2WN(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_HelixZXCY(short crd,long x,long y,long z,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixZXCYOverride2(short crd,long x,long y,long z,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixZXCYWN(short crd,long x,long y,long z,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixZXCYOverride2WN(short crd,long x,long y,long z,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_BufIO(short crd,unsigned short doType,unsigned short doMask,unsigned short doValue,short fifo=0);
GT_API GT_BufDelay(short crd,unsigned short delayTime,short fifo=0);
GT_API GT_BufDA(short crd,short chn,short daValue,short fifo=0);
GT_API GT_BufLmtsOn(short crd,short axis,short limitType,short fifo=0);
GT_API GT_BufLmtsOff(short crd,short axis,short limitType,short fifo=0);
GT_API GT_BufSetStopIo(short crd,short axis,short stopType,short inputType,short inputIndex,short fifo=0);
GT_API GT_BufMove(short crd,short moveAxis,long pos,double vel,double acc,short modal,short fifo=0);
GT_API GT_BufGear(short crd,short gearAxis,long pos,short fifo=0);
GT_API GT_BufGearPercent(short crd,short gearAxis,long pos,short accPercent,short decPercent,short fifo=0);
GT_API GT_BufStopMotion(short crd,short fifo=0);
GT_API GT_BufSetVarValue(short crd,short pageId,TVarInfo *pVarInfo,double value,short fifo=0);
GT_API GT_BufJumpNextSeg(short crd,short axis,short limitType,short fifo=0);
GT_API GT_BufSynchPrfPos(short crd,short encoder,short profile,short fifo=0);
GT_API GT_BufVirtualToActual(short crd,short fifo=0);
GT_API GT_CrdStart(short mask,short option);
GT_API GT_CrdStartStep(short mask,short option);
GT_API GT_CrdStepMode(short mask,short option);
GT_API GT_SetOverride(short crd,double synVelRatio);
GT_API GT_SetOverride2(short crd,double synVelRatio);
GT_API GT_InitLookAhead(short crd,short fifo,double T,double accMax,short n,TCrdData *pLookAheadBuf);
GT_API GT_GetLookAheadSpace(short crd,long *pSpace,short fifo=0);
GT_API GT_GetLookAheadSegCount(short crd,long *pSegCount,short fifo=0);
GT_API GT_CrdClear(short crd,short fifo);
GT_API GT_CrdStatus(short crd,short *pRun,long *pSegment,short fifo=0);
GT_API GT_SetUserSegNum(short crd,long segNum,short fifo=0);
GT_API GT_GetUserSegNum(short crd,long *pSegment,short fifo=0);
GT_API GT_GetUserSegNumWN(short crd,long *pSegment,short fifo=0);
GT_API GT_GetRemainderSegNum(short crd,long *pSegment,short fifo=0);
GT_API GT_SetCrdStopDec(short crd,double decSmoothStop,double decAbruptStop);
GT_API GT_GetCrdStopDec(short crd,double *pDecSmoothStop,double *pDecAbruptStop);
GT_API GT_SetCrdLmtStopMode(short crd,short lmtStopMode);
GT_API GT_GetCrdLmtStopMode(short crd,short *pLmtStopMode);
GT_API GT_GetUserTargetVel(short crd,double *pTargetVel);
GT_API GT_GetSegTargetPos(short crd,long *pTargetPos);
GT_API GT_GetCrdPos(short crd,double *pPos);
GT_API GT_GetCrdVel(short crd,double *pSynVel);
GT_API GT_BufLaserOn(short crd,short fifo=0,short channel=0);
GT_API GT_BufLaserOff(short crd,short fifo=0,short channel=0);
GT_API GT_BufLaserPrfCmd(short crd,double laserPower,short fifo=0,short channel=0);

GT_API GT_SetG0Mode(short crd,short mode);
GT_API GT_GetG0Mode(short crd,short *pMode);

GT_API GT_SetCrdMapBase(short crd,short base);
GT_API GT_GetCrdMapBase(short crd,short *pBase);
GT_API GT_SetCrdBufferMode(short crd,  short bufferMode,short fifo=0);
GT_API GT_GetCrdBufferMode(short crd,short *pBufferMode,short fifo=0);
GT_API GT_GetCrdSegmentTime(short crd,long segmentIndex,double *pSegmentTime,long *pSegmentNumber,short fifo=0);
GT_API GT_GetCrdTime(short crd,TCrdTime *pTime,short fifo=0);

GT_API GT_BufFollowMaster(short crd,TBufFollowMaster *pBufFollowMaster,short fifo=0);
GT_API GT_BufFollowEventCross(short crd,TBufFollowEventCross *pEventCross,short fifo=0);
GT_API GT_BufFollowEventTrigger(short crd,TBufFollowEventTrigger *pEventTrigger,short fifo=0);
GT_API GT_BufFollowStart(short crd,long masterSegment,long slaveSegment,long masterFrameWidth,short fifo=0);
GT_API GT_BufFollowNext(short crd,long width,short fifo=0);
GT_API GT_BufFollowReturn(short crd,double vel,double acc,short smoothPercent,short fifo=0);
GT_API GT_BufLaserFollowMode(short crd,short source,short fifo,short channel,double startPower=0);
GT_API GT_BufLaserFollowRatio(short crd,double ratio,double minPower,double maxPower,short fifo,short channel);
GT_API GT_BufLaserFollowOff(short crd,short fifo,short channel);
GT_API GT_BufLaserFollowSpline(short crd,short tableId,double minPower,double maxPower,short fifo,short channel);
GT_API GT_BufLaserFollowTable(short crd,short tableId,double minPower,double maxPower,short fifo,short channel);


GT_API GTN_SetCrdPrm(short core,short crd,TCrdPrm *pCrdPrm);
GT_API GTN_GetCrdPrm(short core,short crd,TCrdPrm *pCrdPrm);
GT_API GTN_CrdSpace(short core,short crd,long *pSpace,short fifo=0);
GT_API GTN_CrdData(short core,short crd,TCrdData *pCrdData,short fifo=0);

GT_API GTN_LnXY(short core,short crd,long x,long y,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_LnXYOverride2(short core,short crd,long x,long y,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_LnXYWN(short core,short crd,long x,long y,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_LnXYOverride2WN(short core,short crd,long x,long y,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_LnXYG0(short core,short crd,long x,long y,double synVel,double synAcc,short fifo=0);
GT_API GTN_LnXYG0Override2(short core,short crd,long x,long y,double synVel,double synAcc,short fifo=0);
GT_API GTN_LnXYG0WN(short core,short crd,long x,long y,double synVel,double synAcc,long segNum=0,short fifo=0);
GT_API GTN_LnXYG0Override2WN(short core,short crd,long x,long y,double synVel,double synAcc,long segNum=0,short fifo=0);

GT_API GTN_LnXYZ(short core,short crd,long x,long y,long z,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_LnXYZOverride2(short core,short crd,long x,long y,long z,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_LnXYZWN(short core,short crd,long x,long y,long z,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_LnXYZOverride2WN(short core,short crd,long x,long y,long z,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_LnXYZG0(short core,short crd,long x,long y,long z,double synVel,double synAcc,short fifo=0);
GT_API GTN_LnXYZG0Override2(short core,short crd,long x,long y,long z,double synVel,double synAcc,short fifo=0);
GT_API GTN_LnXYZG0WN(short core,short crd,long x,long y,long z,double synVel,double synAcc,long segNum=0,short fifo=0);
GT_API GTN_LnXYZG0Override2WN(short core,short crd,long x,long y,long z,double synVel,double synAcc,long segNum=0,short fifo=0);

GT_API GTN_LnXYZA(short core,short crd,long x,long y,long z,long a,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_LnXYZAOverride2(short core,short crd,long x,long y,long z,long a,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_LnXYZAWN(short core,short crd,long x,long y,long z,long a,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_LnXYZAOverride2WN(short core,short crd,long x,long y,long z,long a,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_LnXYZAG0(short core,short crd,long x,long y,long z,long a,double synVel,double synAcc,short fifo=0);
GT_API GTN_LnXYZAG0Override2(short core,short crd,long x,long y,long z,long a,double synVel,double synAcc,short fifo=0);
GT_API GTN_LnXYZAG0WN(short core,short crd,long x,long y,long z,long a,double synVel,double synAcc,long segNum=0,short fifo=0);
GT_API GTN_LnXYZAG0Override2WN(short core,short crd,long x,long y,long z,long a,double synVel,double synAcc,long segNum=0,short fifo=0);

GT_API GTN_LnXYZACUVW(short core,short crd,long *pPos,short posMask,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_LnXYZACUVWOverride2(short core,short crd,long *pPos,short posMask,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_LnXYZACUVWWN(short core,short crd,long *pPos,short posMask,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_LnXYZACUVWOverride2WN(short core,short crd,long *pPos,short posMask,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_ArcXYR(short core,short crd,long x,long y,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcXYROverride2(short core,short crd,long x,long y,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcXYRWN(short core,short crd,long x,long y,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_ArcXYROverride2WN(short core,short crd,long x,long y,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_ArcXYC(short core,short crd,long x,long y,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcXYCOverride2(short core,short crd,long x,long y,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcXYCWN(short core,short crd,long x,long y,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_ArcXYCOverride2WN(short core,short crd,long x,long y,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_ArcYZR(short core,short crd,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcYZROverride2(short core,short crd,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcYZRWN(short core,short crd,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_ArcYZROverride2WN(short core,short crd,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_ArcYZC(short core,short crd,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcYZCOverride2(short core,short crd,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcYZCWN(short core,short crd,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_ArcYZCOverride2WN(short core,short crd,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_ArcZXR(short core,short crd,long z,long x,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcZXROverride2(short core,short crd,long z,long x,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcZXRWN(short core,short crd,long z,long x,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_ArcZXROverride2WN(short core,short crd,long z,long x,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_ArcZXC(short core,short crd,long z,long x,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcZXCOverride2(short core,short crd,long z,long x,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcZXCWN(short core,short crd,long z,long x,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_ArcZXCOverride2WN(short core,short crd,long z,long x,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_ArcXYZ(short core,short crd,long x,long y,long z,double interX,double interY,double interZ,double synVel,double synAcc,double velEnd,short fifo=0);
GT_API GTN_ArcXYZWN(short core,short crd,long x,long y,long z,double interX,double interY,double interZ,double synVel,double synAcc,double velEnd,long segNum,short fifo=0);
GT_API GTN_ArcXYZOverride2WN(short core,short crd,long x,long y,long z,double interX,double interY,double interZ,double synVel,double synAcc,double velEnd,long segNum,short fifo=0);

GT_API GTN_HelixXYRZ(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd,short fifo=0);
GT_API GTN_HelixXYRZOverride2(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_HelixXYRZWN(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_HelixXYRZOverride2WN(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_HelixXYCZ(short core,short crd,long x,long y,long z,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_HelixXYCZOverride2(short core,short crd,long x,long y,long z,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_HelixXYCZWN(short core,short crd,long x,long y,long z,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_HelixXYCZOverride2WN(short core,short crd,long x,long y,long z,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_HelixYZRX(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_HelixYZRXOverride2(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_HelixYZRXWN(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_HelixYZRXOverride2WN(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_HelixYZCX(short core,short crd,long x,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_HelixYZCXOverride2(short core,short crd,long x,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_HelixYZCXWN(short core,short crd,long x,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_HelixYZCXOverride2WN(short core,short crd,long x,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_HelixZXRY(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_HelixZXRYOverride2(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_HelixZXRYWN(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_HelixZXRYOverride2WN(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_HelixZXCY(short core,short crd,long x,long y,long z,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_HelixZXCYOverride2(short core,short crd,long x,long y,long z,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_HelixZXCYWN(short core,short crd,long x,long y,long z,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_HelixZXCYOverride2WN(short core,short crd,long x,long y,long z,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_BufIO(short core,short crd,unsigned short doType,unsigned short doMask,unsigned short doValue,short fifo=0);
GT_API GTN_BufDelay(short core,short crd,unsigned short delayTime,short fifo=0);
GT_API GTN_BufDA(short core,short crd,short chn,short daValue,short fifo=0);
GT_API GTN_BufLmtsOn(short core,short crd,short axis,short limitType,short fifo=0);
GT_API GTN_BufLmtsOff(short core,short crd,short axis,short limitType,short fifo=0);
GT_API GTN_BufSetStopIo(short core,short crd,short axis,short stopType,short inputType,short inputIndex,short fifo=0);
GT_API GTN_BufMove(short core,short crd,short moveAxis,long pos,double vel,double acc,short modal,short fifo=0);
GT_API GTN_BufGear(short core,short crd,short gearAxis,long pos,short fifo=0);
GT_API GTN_BufGearPercent(short core,short crd,short gearAxis,long pos,short accPercent,short decPercent,short fifo=0);
GT_API GTN_BufStopMotion(short core,short crd,short fifo=0);
GT_API GTN_BufSetVarValue(short core,short crd,short pageId,TVarInfo *pVarInfo,double value,short fifo=0);
GT_API GTN_BufJumpNextSeg(short core,short crd,short axis,short limitType,short fifo=0);
GT_API GTN_BufSynchPrfPos(short core,short crd,short encoder,short profile,short fifo=0);
GT_API GTN_BufVirtualToActual(short core,short crd,short fifo=0);
GT_API GTN_BufEnableDoBitPulse(short core,short crd,short doType,short doIndex,unsigned short highLevelTime,unsigned short lowLevelTime,long pulseNum,short firstLevel,short fifo);
GT_API GTN_BufDisableDoBitPulse(short core,short crd,short doType,short doIndex,short fifo);

GT_API GTN_CrdStart(short core,short mask,short option);
GT_API GTN_CrdStartStep(short core,short mask,short option);
GT_API GTN_CrdStepMode(short core,short mask,short option);
GT_API GTN_SetOverride(short core,short crd,double synVelRatio);
GT_API GTN_SetOverride2(short core,short crd,double synVelRatio);
GT_API GTN_InitLookAhead(short core,short crd,short fifo,double T,double accMax,short n,TCrdData *pLookAheadBuf);
GT_API GTN_GetLookAheadSpace(short core,short crd,long *pSpace,short fifo=0);
GT_API GTN_GetLookAheadSegCount(short core,short crd,long *pSegCount,short fifo=0);
GT_API GTN_CrdClear(short core,short crd,short fifo);
GT_API GTN_CrdStatus(short core,short crd,short *pRun,long *pSegment,short fifo=0);
GT_API GTN_SetUserSegNum(short core,short crd,long segNum,short fifo=0);
GT_API GTN_GetUserSegNum(short core,short crd,long *pSegment,short fifo=0);
GT_API GTN_GetUserSegNumWN(short core,short crd,long *pSegment,short fifo=0);
GT_API GTN_GetRemainderSegNum(short core,short crd,long *pSegment,short fifo=0);
GT_API GTN_SetCrdStopDec(short core,short crd,double decSmoothStop,double decAbruptStop);
GT_API GTN_GetCrdStopDec(short core,short crd,double *pDecSmoothStop,double *pDecAbruptStop);
GT_API GTN_SetCrdLmtStopMode(short core,short crd,short lmtStopMode);
GT_API GTN_GetCrdLmtStopMode(short core,short crd,short *pLmtStopMode);
GT_API GTN_GetUserTargetVel(short core,short crd,double *pTargetVel);
GT_API GTN_GetSegTargetPos(short core,short crd,long *pTargetPos);
GT_API GTN_GetCrdPos(short core,short crd,double *pPos);
GT_API GTN_GetCrdVel(short core,short crd,double *pSynVel);
GT_API GTN_BufLaserOn(short core,short crd,short fifo=0,short channel=0);
GT_API GTN_BufLaserOff(short core,short crd,short fifo=0,short channel=0);
GT_API GTN_BufLaserPrfCmd(short core,short crd,double laserPower,short fifo=0,short channel=0);

GT_API GTN_BufLaserFollowMode(short core,short crd,short source,short fifo,short channel,double startPower);
GT_API GTN_BufLaserFollowRatio(short core,short crd,double ratio,double minPower,double maxPower,short fifo,short channel);
GT_API GTN_BufLaserFollowOff(short core,short crd,short fifo,short channel);
GT_API GTN_BufLaserFollowSpline(short core,short crd,short tableId,double minPower,double maxPower,short fifo,short channel);
GT_API GTN_BufLaserFollowTable(short core,short crd,short tableId,double minPower,double maxPower,short fifo,short channel);

GT_API GTN_BufFollowMaster(short core,short crd,TBufFollowMaster *pBufFollowMaster,short fifo=0);
GT_API GTN_BufFollowEventCross(short core,short crd,TBufFollowEventCross *pEventCross,short fifo=0);
GT_API GTN_BufFollowEventTrigger(short core,short crd,TBufFollowEventTrigger *pEventTrigger,short fifo=0);
GT_API GTN_BufFollowStart(short core,short crd,long masterSegment,long slaveSegment,long masterFrameWidth,short fifo=0);
GT_API GTN_BufFollowNext(short core,short crd,long width,short fifo=0);
GT_API GTN_BufFollowReturn(short core,short crd,double vel,double acc,short smoothPercent,short fifo=0);

GT_API GTN_BufStop(short core,short crd,long mask,long option,short fifo);
GT_API GTN_BufMoveJog(short core,short crd,short moveAxis,double vel,double acc,short modal,short fifo);

GT_API GTN_SetG0Mode(short core,short crd,short mode);
GT_API GTN_GetG0Mode(short core,short crd,short *pMode);

GT_API GTN_SetCrdMapBase(short core,short crd,short base);
GT_API GTN_GetCrdMapBase(short core,short crd,short *pBase);
GT_API GTN_SetCrdBufferMode(short core,short crd,  short bufferMode,short fifo=0);
GT_API GTN_GetCrdBufferMode(short core,short crd,short *pBufferMode,short fifo=0);
GT_API GTN_GetCrdSegmentTime(short core,short crd,long segmentIndex,double *pSegmentTime,long *pSegmentNumber,short fifo=0);
GT_API GTN_GetCrdTime(short core,short crd,TCrdTime *pTime,short fifo=0);

GT_API GT_GetCmdCount(short crd,short *pResult,short fifo);

GT_API GTN_SetCrdContourErrorControl(short core,short crd,short enable,double percent);
GT_API GTN_GetCrdContourErrorControl(short core,short crd,short *pEnable,double *pPercent);

/*-----------------------------------------------------------*/
/* Compensate                                                */
/*-----------------------------------------------------------*/
GT_API GT_SetBacklash(short axis,long value,double changeValue,long dir);
GT_API GT_GetBacklash(short axis,long *pValue,double *pChangeValue,long *pDir);
GT_API GT_SetLeadScrewComp(short axis,short n,long startPos,long lenPos,long *pPositive,long *pNegative);
GT_API GT_EnableLeadScrewComp(short axis,short mode);
GT_API GT_SetLeadScrewCrossComp(short axis,short n,long startPos,long lenPos,long *pPositive,long *pNegative,short link);
GT_API GT_EnableLeadScrewCrossComp(short axis,short mode);
GT_API GT_GetCompensate(short axis,double *pPitchError,double *pCrossError,double *pBacklashError,double *pEncPos,double *pPrfPos);

GT_API GTN_SetBacklash(short core,short axis,long value,double changeValue,long dir);
GT_API GTN_GetBacklash(short core,short axis,long *pValue,double *pChangeValue,long *pDir);
GT_API GTN_SetLeadScrewComp(short core,short axis,short n,long startPos,long lenPos,long *pPositive,long *pNegative);
GT_API GTN_EnableLeadScrewComp(short core,short axis,short mode);
GT_API GTN_SetLeadScrewCrossComp(short core,short axis,short n,long startPos,long lenPos,long *pPositive,long *pNegative,short link);
GT_API GTN_EnableLeadScrewCrossComp(short core,short axis,short mode);
GT_API GTN_GetCompensate(short core,short axis,double *pPitchError,double *pCrossError,double *pBacklashError,double *pEncPos,double *pPrfPos);


typedef struct
{
	short n;
	long startPos;
	long lenPos;
	long *pCompPos;
	long *pCompNeg;
} TLeadScrewPrm;

GT_API GT_SetLeadScrewTable(short axis,TLeadScrewPrm *pPrm);
GT_API GT_EnableLeadScrewTable(short axis,long error=0);
GT_API GT_DisableLeadScrewTable(short axis);
GT_API GT_GetLeadScrewTablePrfPosCount(long encPos,TLeadScrewPrm *pPrm,short *pCountPositive,short *pCountNegative);
GT_API GT_GetLeadScrewTablePrfPosPositive(long encPos,TLeadScrewPrm *pPrm,short index,long *pPrfPosPositive);
GT_API GT_GetLeadScrewTablePrfPosNegative(long encPos,TLeadScrewPrm *pPrm,short index,long *pPrfPosNegative);

GT_API GTN_SetLeadScrewTable(short core,short axis,TLeadScrewPrm *pPrm);
GT_API GTN_EnableLeadScrewTable(short core,short axis,long error=0);
GT_API GTN_DisableLeadScrewTable(short core,short axis);
GT_API GTN_GetLeadScrewTablePrfPosCount(short core,long encPos,TLeadScrewPrm *pPrm,short *pCountPositive,short *pCountNegative);
GT_API GTN_GetLeadScrewTablePrfPosPositive(short core,long encPos,TLeadScrewPrm *pPrm,short index,long *pPrfPosPositive);
GT_API GTN_GetLeadScrewTablePrfPosNegative(short core,long encPos,TLeadScrewPrm *pPrm,short index,long *pPrfPosNegative);

typedef struct
{
	short count[2];
	long posBegin[2];
	long step[2];
} TCompensate2DTable;

typedef struct
{
	short enable;
	short tableIndex;
	short axisType[2];
	short axisIndex[2];
} TCompensate2D;

GT_API GT_SetCompensate2DTable(short tableIndex,TCompensate2DTable *pTable,long *pData,short extend);
GT_API GT_GetCompensate2DTable(short tableIndex,TCompensate2DTable *pTable,short *pExtend);
GT_API GT_SetCompensate2DTableRotationAngle(short tableIndex,short enable,double rotationAngle);
GT_API GT_GetCompensate2DTableRotationAngle(short tableIndex,short *pEnable,double *pRotationAngle);
GT_API GT_SetCompensate2D(short axis,TCompensate2D *pComp2d);
GT_API GT_GetCompensate2D(short axis,TCompensate2D *pComp2d);
GT_API GT_GetCompensate2DValue(short axis,double *pValue);

GT_API GTN_SetCompensate2DTable(short core,short tableIndex,TCompensate2DTable *pTable,long *pData,short extend);
GT_API GTN_GetCompensate2DTable(short core,short tableIndex,TCompensate2DTable *pTable,short *pExtend);
GT_API GTN_SetCompensate2DTableRotationAngle(short core,short tableIndex,short enable,double rotationAngle);
GT_API GTN_GetCompensate2DTableRotationAngle(short core,short tableIndex,short *pEnable,double *pRotationAngle);
GT_API GTN_SetCompensate2D(short core,short axis,TCompensate2D *pComp2d);
GT_API GTN_GetCompensate2D(short core,short axis,TCompensate2D *pComp2d);
GT_API GTN_GetCompensate2DValue(short core,short axis,double *pValue);
GT_API GTN_SetCompensate2DMode(short core,short axis,short mode);
GT_API GTN_GetCompensate2DMode(short core,short axis,short *pMode);

/*-----------------------------------------------------------*/
/* IO and Encoder                                            */
/*-----------------------------------------------------------*/
GT_API GT_SetDo(short doType,long value);
GT_API GT_SetDoBit(short doType,short doIndex,short value);
GT_API GT_GetDo(short doType,long *pValue);
GT_API GT_SetDoBitReverse(short doType,short doIndex,short value,short reverseTime);
GT_API GT_GetDi(short diType,long *pValue);
GT_API GT_GetDiReverseCount(short diType,short diIndex,unsigned long *pReverseCount,short count=1);
GT_API GT_SetDiReverseCount(short diType,short diIndex,unsigned long *pReverseCount,short count=1);
GT_API GT_GetDiRaw(short diType,long *pValue);
GT_API GT_GetDiEx(short diType,long *pValue,short count);

GT_API GT_SetDac(short dac,short *pValue,short count=1);
GT_API GT_GetDac(short dac,short *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAdc(short adc,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAdcValue(short adc,short *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAuAdc(short adc,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAuAdcValue(short adc,short *pValue,short count=1,unsigned long *pClock=NULL);

GT_API GT_SetEncPos(short encoder,long encPos);
GT_API GT_GetEncPos(short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetEncPosPre(short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetEncVel(short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);

GT_API GT_SetPlsPos(short encoder,long encPos);
GT_API GT_GetPlsPos(short pulse,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetPlsVel(short pulse,double *pValue,short count=1,unsigned long *pClock=NULL);

GT_API GT_SetAuEncPos(short encoder,long encPos);
GT_API GT_GetAuEncPos(short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAuEncVel(short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);


GT_API GTN_SetDo(short core,short doType,long value);
GT_API GTN_SetDoEx(short core,short doType,long *pValue,short count);
GT_API GTN_SetDoBit(short core,short doType,short doIndex,short value);
GT_API GTN_GetDo(short core,short doType,long *pValue);
GT_API GTN_GetDoEx(short core,short doType,long *pValue,short count);
GT_API GTN_SetDoBitReverse(short core,short doType,short doIndex,short value,short reverseTime);
GT_API GTN_EnableDoBitPulse(short core,short doType,short doIndex,unsigned short highLevelTime,unsigned short lowLevelTime,long pulseNum,short firstLevel);
GT_API GTN_DisableDoBitPulse(short core,short doType,short doIndex);
GT_API GTN_GetDi(short core,short diType,long *pValue);
GT_API GTN_GetDiReverseCount(short core,short diType,short diIndex,unsigned long *pReverseCount,short count=1);
GT_API GTN_SetDiReverseCount(short core,short diType,short diIndex,unsigned long *pReverseCount,short count=1);
GT_API GTN_GetDiRaw(short core,short diType,long *pValue);
GT_API GTN_GetDiEx(short core,short diType,long *pValue,short count);

GT_API GTN_SetGtmDoBit(short core,short station,short slot,short doIndex,short *pValue,short count=1);
GT_API GTN_GetGtmDoBit(short core,short station,short slot,short doIndex,short *pValue,short count=1);
GT_API GTN_GetGtmDiBit(short core,short station,short slot,short diIndex,short *pValue,short count=1);

GT_API GTN_SetDac(short core,short dac,short *pValue,short count=1);
GT_API GTN_GetDac(short core,short dac,short *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_SetAuDac(short core,short dac,short *pValue,short count=1);
GT_API GTN_GetAuDac(short core,short dac,short *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAdc(short core,short adc,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAdcValue(short core,short adc,short *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAuAdc(short core,short adc,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAuAdcValue(short core,short adc,short *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetEncLineNum(short core,short encoder,long *pLineNum,short count,unsigned long *pClock);
GT_API GTN_GetEncType(short core,short encoder,short *pType,short count,unsigned long *pClock);
GT_API GTN_SetGratingScale(short core,short index,short *pScale,short count=1);
GT_API GTN_GetGratingScale(short core,short index,short *pScale,short count=1);
GT_API GTN_SetEncPos(short core,short encoder,long encPos);
GT_API GTN_GetEncPos(short core,short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetEncPosPre(short core,short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetEncVel(short core,short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);

GT_API GTN_SetPlsPos(short core,short encoder,long encPos);
GT_API GTN_GetPlsPos(short core,short pulse,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetPlsVel(short core,short pulse,double *pValue,short count=1,unsigned long *pClock=NULL);

GT_API GTN_SetAuEncPos(short core,short encoder,long encPos);
GT_API GTN_GetAuEncPos(short core,short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAuEncVel(short core,short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);

GT_API GTN_GetAbsEncPos(short core,short encoder,long *pValue,short mode=0,short param=0);
/*-----------------------------------------------------------*/
/* ExtModule                                                 */
/*-----------------------------------------------------------*/
GT_API GTN_ExtModuleInit(short core,short method=1);
GT_API GTN_SetILinkManuMode(short core,short station);
GT_API GTN_GetILinkManuId(short core,short station,short autoId,short *manuId);
GT_API GTN_GetILinkAutoId(short core,short station,short manuId,short *autoId);
GT_API GTN_SetExtDoBit(short core,short doIndex,short value);
GT_API GTN_GetExtDoBit(short core,short doIndex,short *pValue);
GT_API GTN_SetExtDo(short core,short doIndex,long value,long mask);
GT_API GTN_GetExtDo(short core,short doIndex,long *pValue);
GT_API GTN_GetExtDi(short core,short diIndex,long *pValue);
GT_API GTN_SetExtAoValue(short core,short index,short *pValue,short count=1);
GT_API GTN_GetExtAiValue(short core,short index,short *pValue,short count=1);
GT_API GTN_SetExtAo(short core,short index,double *pValue,short count=1);
GT_API GTN_GetExtAo(short core,short index,double *pValue,short count=1);
GT_API GTN_GetExtAi(short core,short index,double *pValue,short count=1);

GT_API GTN_SetILinkDo(short core,short station,short module,unsigned short data,unsigned short mask);
GT_API GTN_GetILinkDi(short core,short station,short module,unsigned short *data);
GT_API GTN_SetILinkAo(short core,short station,short module,short channel,double data);
GT_API GTN_GetILinkAi(short core,short station,short module,short channel,double *data);

/*-----------------------------------------------------------*/
/* Pos Compare                                               */
/*-----------------------------------------------------------*/
#define POS_COMPARE_MODE_FIFO                       (0)
#define POS_COMPARE_MODE_LINEAR                     (1)
#define POS_COMPARE_MODE_EQUIDISTANT                (2)

#define POS_COMPARE_OUTPUT_PULSE                    (0)
#define POS_COMPARE_OUTPUT_LEVEL                    (1)
#define POS_COMPARE_OUTPUT_AUTO                     (2)

#define POS_COMPARE_SOURCE_ENCODER                  (0)
#define POS_COMPARE_SOURCE_PULSE                    (1)


typedef struct
{
	short mode;
	short dimension;
	short sourceMode;
	short sourceX;
	short sourceY;
	short outputMode;
	short outputCounter;
	unsigned short outputPulseWidth;
	unsigned short errorBand;
} TPosCompareMode;

typedef struct
{
	unsigned long count;
	unsigned short hso;
	unsigned short gpo;

	long startPos;
	long interval;
} TPosCompareLinear;

typedef struct
{
	unsigned long count;
	unsigned short hso;
	unsigned short gpo;

	long startPosX;
	long startPosY;
	long intervalX;
	long intervalY;
} TPosCompareLinear2D;


typedef struct
{
	long pos;
	unsigned short hso;
	unsigned short gpo;
	unsigned long segmentNumber;
} TPosCompareData;

typedef struct
{
	long posX;
	long posY;
	unsigned short hso;
	unsigned short gpo;
	unsigned long segmentNumber;
} TPosCompareData2D;

typedef struct
{
	unsigned short mode;
	unsigned short run;
	unsigned short space;
	unsigned long pulseCount;
	unsigned short hso;
	unsigned short gpo;
	unsigned long segmentNumber;
} TPosCompareStatus;

typedef struct
{
	unsigned short config;
	unsigned short fifoEmpty;
	unsigned short head;
	unsigned short tail;
	unsigned long commandReceive;
	unsigned long commandSend;
	long posX;
	long posY;
} TPosCompareInfo;

typedef struct
{
	unsigned long count;
	unsigned short hso;
	unsigned short gpo;
	long startPosX;
	long startPosY;
	long syncPos;
	long time;
	short reserve[20];
} TPosComparePsoPrm;

typedef struct
{
	unsigned long count;
	unsigned short hso;
	unsigned short gpo;
	long startPosX;
	long startPosY;
	long syncPos;
	long time;
	short pulseWidth;
	short pad;
} TPosComparePsoPrmPro;


typedef struct
{
	short mode;
	unsigned short count;
	short highLevel;
	short lowLevel;
	short resver[20];
} TPosCompareContinueMode;

typedef struct
{
	short	referenceX;
	short	referenceY;
	short	pad1[2];
	double	pad2[2];
} TPosCompareReferencePrm;

typedef struct
{
	short mode;          // 0���������1����Ĭ�����������2�����յ�ǰָ��������Ϣ���
	short timeScale;     // ʱ�侫�ȣ�0��1us��1:0.1us
	short pad1[2];
	double pulseWidth;
	double pad2[3];
}THsoPulsePrm;

typedef struct
{
	short outputMode;
	short level;
	short reserve1[2];
	double highLevelTime;
	double lowLevelTime;
	double reserve2[4];
}TPosComparePulse;

typedef struct
{
	short outputMode;
	short level;
	long count;
	double highLevelTime;
	double lowLevelTime;
	double reserve2[4];
}TPosCompareMultiPulse;

typedef struct
{
	long count;
	short reserve1[2];
	double reserve2[4];
}TPosComparePulseStatus;

typedef struct
{
	short mode;                        // 0��FIFOģʽ��1��Linearģʽ 2���ȼ�����ģʽ
	short dimension;                   // 1��1D��2��2D
	short sourceMode;                  // 0���������� 1�����������
	short source[8];                   // �������Ƚ�Դ
	short outputMode;                  // ���ģʽ��0:���� 1:��ƽ2����ƽ�Զ���ת(��ƽģʽ���������ƽ�Զ���ת������posCompareData��ƽӰ��)
	short outputCounter;               // ����
	unsigned short outputPulseWidth;   // ���������,��λΪ1us����ƽģʽ�ò�����Ч
	unsigned short errorBand;          // ��άλ�ñȽ��������
	short reserve1[2];
	double reserve2[16];
} TPosCompareModeEx;

typedef struct
{
	unsigned long count;
	unsigned short hso;
	unsigned short gpo;
	long startPosX;
	long startPosY;
	long time;

	short pad1;
	short multiNumber;
	long scale[6];
	double syncPosArray[256];
} TPosComparePsoPrmEx;

GT_API GT_PosCompareStart(short core,short posCompareIndex);
GT_API GT_PosCompareStop(short core,short posCompareIndex);
GT_API GT_PosCompareClear(short core,short posCompareIndex);
GT_API GT_PosCompareStatus(short core,short posCompareIndex,TPosCompareStatus *pStatus);
GT_API GT_PosCompareData(short core,short posCompareIndex,TPosCompareData *pData);
GT_API GT_PosCompareData2D(short core,short posCompareIndex,TPosCompareData2D *pData);
GT_API GT_SetPosCompareMode(short core,short posCompareIndex,TPosCompareMode *pMode);
GT_API GT_GetPosCompareMode(short core,short posCompareIndex,TPosCompareMode *pMode);
GT_API GT_SetPosCompareLinear(short core,short posCompareIndex,TPosCompareLinear *pLinear);
GT_API GT_GetPosCompareLinear(short core,short posCompareIndex,TPosCompareLinear *pLinear);
GT_API GT_SetPosCompareLinear2D(short core,short posCompareIndex,TPosCompareLinear2D *pLinear);
GT_API GT_GetPosCompareLinear2D(short core,short posCompareIndex,TPosCompareLinear2D *pLinear);
GT_API GT_PosCompareInfo(short core,short posCompareIndex,TPosCompareInfo *pInfo);
GT_API GT_SetPosComparePsoPrm(short core,short posCompareIndex,TPosComparePsoPrm *pPrm);
GT_API GT_GetPosComparePsoPrm(short core,short posCompareIndex,TPosComparePsoPrm *pPrm);

GT_API GTN_PosCompareStart(short core,short posCompareIndex);
GT_API GTN_PosCompareStop(short core,short posCompareIndex);
GT_API GTN_PosCompareClear(short core,short posCompareIndex);
GT_API GTN_PosCompareStatus(short core,short posCompareIndex,TPosCompareStatus *pStatus);
GT_API GTN_PosCompareData(short core,short posCompareIndex,TPosCompareData *pData);
GT_API GTN_PosCompareData2D(short core,short posCompareIndex,TPosCompareData2D *pData);
GT_API GTN_PosComparePulse(short core,short posCompareIndex,short outputMode,short level,unsigned short outputPulseWidth);
GT_API GTN_SetPosComparePulseCount(short core,short posCompareIndex,long count);
GT_API GTN_PosComparePulseEx(short core,short posCompareIndex,TPosComparePulse *pPosComparePulse);
GT_API GTN_PosCompareMultiPulse(short core,short posCompareIndex,TPosCompareMultiPulse *pPosComparePulse);
GT_API GTN_GetPosComparePulseStatus(short core,short posCompareIndex,TPosComparePulseStatus *pPosComparePulseStatus);
GT_API GTN_SetPosCompareMode(short core,short posCompareIndex,TPosCompareMode *pMode);
GT_API GTN_GetPosCompareMode(short core,short posCompareIndex,TPosCompareMode *pMode);
GT_API GTN_SetPosCompareContinueMode(short core,short posCompareIndex,TPosCompareContinueMode *pMode);
GT_API GTN_GetPosCompareContinueMode(short core,short posCompareIndex,TPosCompareContinueMode *pMode);
GT_API GTN_SetPosCompareLinear(short core,short posCompareIndex,TPosCompareLinear *pLinear);
GT_API GTN_GetPosCompareLinear(short core,short posCompareIndex,TPosCompareLinear *pLinear);
GT_API GTN_SetPosCompareLinear2D(short core,short posCompareIndex,TPosCompareLinear2D *pLinear);
GT_API GTN_GetPosCompareLinear2D(short core,short posCompareIndex,TPosCompareLinear2D *pLinear);
GT_API GTN_PosCompareInfo(short core,short posCompareIndex,TPosCompareInfo *pInfo);
GT_API GTN_PosCompareHsOn(short core,short posCompareIndex,short link,unsigned short threshold);
GT_API GTN_PosCompareHsOff(short core,short posCompareIndex);
GT_API GTN_PosCompareSpace(short core,short posCompareIndex,unsigned short *pSpace);
GT_API GTN_SetPosComparePsoPrm(short core,short posCompareIndex,TPosComparePsoPrm *pPrm);
GT_API GTN_GetPosComparePsoPrm(short core,short posCompareIndex,TPosComparePsoPrm *pPrm);
GT_API GTN_SetPosCompareStartLevel(short core,short posCompareIndex,short type,short startLevel);
GT_API GTN_SetPosCompareReference(short core,short posCompareIndex,TPosCompareReferencePrm *pPrm);
GT_API GTN_GetPosCompareReference(short core,short posCompareIndex,TPosCompareReferencePrm *pPrm);
GT_API GTN_SetHsoPulsePrm(short core,short station,short hsoIndex,THsoPulsePrm *pPem,short hsoCount=1);
GT_API GTN_GetHsoPulsePrm(short core,short station,short hsoIndex,THsoPulsePrm *pPem,short hsoCount=1);
GT_API GTN_SetPosCompareModeEx(short core,short posCompareIndex,TPosCompareModeEx *pMode);
GT_API GTN_GetPosCompareModeEx(short core,short posCompareIndex,TPosCompareModeEx *pMode);
GT_API GTN_SetPosComparePsoPrmEx(short core,short posCompareIndex,TPosComparePsoPrmEx *pPrm);
GT_API GTN_GetPosComparePsoPrmEx(short core,short posCompareIndex,TPosComparePsoPrmEx *pPrm);
#define POS_COMPARE_THRESHOLD_DEFAULT                      (0)     //λ�ý����û����õ�������Χ�󣬸��������㷨�ҵ����ŵ������
#define POS_COMPARE_THRESHOLD_ZERO	              (1)     //λ�ý����û����õ�������Χ���������    
#define POS_COMPARE_THRESHOLD_FPGA	              (2)     //λ�ý����û����õ�������Χ�󣬸�������Ӧ�㷨�ҵ����ŵ������
GT_API GTN_SetPosCompareThresholdMode(short core,short index,short mode);
GT_API GTN_GetPosCompareThresholdMode(short core,short index,short *pMode);

#define POS_COMPARE_MODE_PSO_SYNC_EXTERNAL_SIGNAL	(1)
#define POS_COMPARE_MODE_PSO_SYNC_INTERNAL_SIGNAL	(2)

GT_API GTN_SetPosComparePsoSyncPrm(short core,short posCompareIndex,short psoSyncMode,double frq=100);

#define COMPARE_SEND_DATA_MAX			(30)
#define COMPARE_DATA_MAX				(4096)
#define COMPARE_STEP_MAX				(0x1fff)
#define COMPARE_MAX_NUM					(0x3fffffff)


/*-----------------------------------------------------------*/
/* Laser and Scan                                            */
/*-----------------------------------------------------------*/
#define FIFO_MODE_STATIC                  (0)
#define FIFO_MODE_DYNAMIC                 (1)

#define SCAN_STATUS_WAIT                  (0)
#define SCAN_STATUS_RUN	                  (1)
#define SCAN_STATUS_DONE                  (2)

struct TScanInit
{
	int lookAheadNum;
	double time;
	double radiusRatio;
};

typedef struct
{
	unsigned long segmentNumber;
	unsigned short commandNumber;
	unsigned short prfVel;
	unsigned short fifoEmpty;
	unsigned short head;
	unsigned short tail;
	unsigned long commandReceive;
	unsigned long commandSend;
	unsigned long reserve[6];
} TScanInfo;

typedef struct
{
	short enable;
	short superposeSrc;
	short superposeAxisX;
	short superposeAxisY;
	double xCoefficient;
	double yCoefficient;
	double xVelCoefficient;
	double yVelCoefficient;
}TScanPosSuperposeParameter;

typedef struct
{
	unsigned short hso;
	unsigned short powerMode;
	unsigned short power;
	unsigned short powerMax;
	unsigned short powerMin;
	unsigned short frequency;
	unsigned short pulseWidth;
} TLaserInfo;

typedef struct
{
	short n;
	double startVel;
	double power;
}TLaserPowerPrm;

typedef struct
{
	short n;
	double startVel;
	double velStep;
	double *power;
}TLaserPowerTable;

typedef struct
{
	short corrX[65][65];
	short corrY[65][65];
}TScanCorrectionTableData;


GT_API GT_LaserAo(short value,unsigned short laserChannel=0);
GT_API GT_SetHSIOOpt(unsigned short value,short laserChannel=0);
GT_API GT_GetHSIOOpt(unsigned short *pValue,short laserChannel=0);
GT_API GT_SetLaserMode(unsigned short laserMode);
GT_API GT_LaserPowerMode(short laserPowerMode,double maxValue,double minValue,short laserChannel=0,short delayMode=0);
GT_API GT_LaserPrfCmd(double power,unsigned short laserChannel=0);
GT_API GT_LaserOutFrq(double outFrq,unsigned short laserChannel=0);
GT_API GT_SetPulseWidth(unsigned short width,unsigned short laserChannel=0);
GT_API GT_SetLevelDelay(unsigned short highLevelDelay,unsigned short lowLevelDelay,unsigned short laserChannel=0);
GT_API GT_LaserInfo(TLaserInfo *pLaserInfo,short laserChannel=0);

GT_API GTN_ScanInit(short core,TScanInit *pScanInit=NULL,double jumpAcc=0,double markAcc=0,short scan=1);
GT_API GTN_ScanCrdDataEnd(short core,short scan=1);
GT_API GTN_SetScanLaserLink(short core,short link,short scan=1);
GT_API GTN_GetScanLaserLink(short core,short *pLink,short scan=1);
GT_API GTN_SetScanMode(short core,short mode,short scan=1);
GT_API GTN_GetScanMode(short core,short *pMode,short scan=1);
GT_API GTN_ClearScanStatus(short core,short scan=1);
GT_API GTN_ScanGetCrdPos(short core,short *pPos,short scan=1);
GT_API GTN_ScanJump(short core,short x,short y,double vel,short scan=1);
GT_API GTN_ScanJumpPoint(short core,short x,short y,double vel,long motionDelayTime,long laserDelayTime,short scan=1);
GT_API GTN_ScanTimeJump(short core,short x,short y,unsigned short time,short scan=1);
GT_API GTN_ScanTimeJumpPoint(short core,short x,short y,unsigned short time,long motionDelayTime,long laserDelayTime,short scan=1);
GT_API GTN_ScanMark(short core,short x,short y,double vel,short scan=1);
GT_API GTN_ScanTimeMark(short core,short x,short y,unsigned short time,short scan=1);
GT_API GTN_ScanBufLaserPrfCmd(short core,double laserPower,short scan=1);
GT_API GTN_ScanBufIO(short core,unsigned short doType,unsigned short doMask,unsigned short doValue,short scan=1);
GT_API GTN_ScanBufDelay(short core,long time,short scan=1);
GT_API GTN_ScanBufDA(short core,unsigned short chn,short value,short scan=1);
GT_API GTN_ScanBufAO(short core,unsigned short chn,double voltage,short scan=1);
GT_API GTN_ScanBufLaserDelay(short core,short laserOnDelay,short laserOffDelay,short scan=1);
GT_API GTN_ScanBufLaserDelayLong(short core,long laserOnDelay,long laserOffDelay,short scan=1);
GT_API GTN_ScanBufLaserOutFrq(short core,double outFrq,short scan=1);
GT_API GTN_ScanBufSetPulseWidth(short core,unsigned short width,short scan=1);
GT_API GTN_ScanBufLaserOn(short core,short scan=1);
GT_API GTN_ScanBufLaserOff(short core,short scan=1);
GT_API GTN_ScanBufStop(short core,short scan=1);
GT_API GTN_ScanLaserIntervalOnList(short core,long time,short scan=1);
GT_API GTN_SetScanDelayTime(short core,unsigned short maxJumpDelay,unsigned short markDelay,unsigned short multiMarkDelayConst,short scan=1);
GT_API GTN_SetScanDelayMode(short core,short multiMarkDelayMode,unsigned short multiMarkLaserOffDelay,unsigned short minJumpDelay,unsigned short jumpDelayLengthLimit,short scan=1);
GT_API GTN_ScanStop(short core,short stopType,short scan=1);
GT_API GTN_ScanCrdSpace(short core,short *pSpace,short scan=1);
GT_API GTN_ScanCrdStart(short core,short scan=1);
GT_API GTN_ScanCrdClear(short core,short scan=1);
GT_API GTN_ScanCrdStatus(short core,short *pRun,short *pCmdId,short scan=1);

GT_API GTN_SetScanPosSuperposeParameter(short core,short scan,TScanPosSuperposeParameter param);
GT_API GTN_GetScanPosSuperposeParameter(short core,short scan,TScanPosSuperposeParameter *pParam);
GT_API GTN_ScanSetCorrectionTable(short core,short scan,TScanCorrectionTableData *pParam);
GT_API GTN_ScanCorrectionOn(short core,short scan);
GT_API GTN_ScanCorrectionOff(short core,short scan);
GT_API GTN_ScanGenerateCorrectionTable(short core,double paraX,double paraY,short rangeX,short rangeY,TScanCorrectionTableData *pParam);

GT_API GTN_LaserOn(short core,short laserChannel=0);
GT_API GTN_LaserOff(short core,short laserChannel=0);
GT_API GTN_LaserOnStatus(short core,unsigned short *pValue,short laserChannel=0);
GT_API GTN_LaserPowerMode(short core,short laserPowerMode,double maxValue,double minValue,short laserChannel=0);
GT_API GTN_LaserPrfCmd(short core,double power,short laserChannel=0);
GT_API GTN_LaserOutFrq(short core,double outFrq,short laserChannel=0);
GT_API GTN_SetPulseWidth(short core,unsigned short width,short laserChannel=0);
GT_API GTN_SetLevelDelay(short core,unsigned long highLevelDelay,unsigned long lowLevelDelay,short laserChannel=0);
GT_API GTN_LaserInfo(short core,TLaserInfo *pLaserInfo,short laserChannel=0);


GT_API GTN_ScanInfo(short core,TScanInfo *pScanInfo,short scan=1);
GT_API GTN_GetScanExecuteTime(short core,short scan,double *pExecuteTime);
GT_API GTN_ClearScanExecuteTime(short core,short scan=1);
GT_API GTN_ScanHsOn(short core,short scan=1,short link=1,unsigned short threshold=200);
GT_API GTN_ScanHsOff(short core,short scan=1);

GT_API GTN_ScanLaserOn(short core,short scan=1);
GT_API GTN_ScanLaserOff(short core,short scan=1);
GT_API GTN_ScanLaserOnStatus(short core,unsigned short *pValue,short scan=1);
GT_API GTN_ScanSetLaserMode(short core,unsigned short laserMode, short scan=1);
GT_API GTN_ScanLaserPowerMode(short core,short laserPowerMode,double maxValue,double minValue, short scan=1);
GT_API GTN_ScanLaserPrfCmd(short core,double power, short scan=1);
GT_API GTN_ScanLaserOutFrq(short core,double outFrq, short scan=1);
GT_API GTN_ScanSetPulseWidth(short core,unsigned short width, short scan=1);
GT_API GTN_ScanSetLevelDelay(short core,unsigned short highLevelDelay,unsigned short lowLevelDelay, short scan=1);
GT_API GTN_ScanSetDa(short core,short chn,short value,short scan=1);
GT_API GTN_ScanLaserInfo(short core,TLaserInfo *pLaserInfo, short scan=1);

GT_API GTN_ScanSetMotionWithLaserControl(short core,short laserCtrlEnable,short scan=1);
GT_API GTN_ScanGetMotionWithLaserControl(short core,short *pLaserCtrlEnable,short scan=1);

GT_API GTN_SetHsoPwmLink(short core,short station,short hsoIndex);
GT_API GTN_GetHsoPwmLink(short core,short station,short *pHsoIndex);

/*-----------------------------------------------------------*/
/* DLM                                                       */
/*-----------------------------------------------------------*/
#define DLM_FUNCTION_EVENT							(0)
#define DLM_FUNCTION_TIMER							(1)
#define DLM_FUNCTION_BACKGROUND						(2)
#define DLM_FUNCTION_COMMAND						(3)

#define DLM_FUNCTION_PROCEDURE						(7)

#define DLM_FUNCTION_PROFILE_EVENT					(8)
#define DLM_FUNCTION_PROFILE						(9)
#define DLM_FUNCTION_PROFILE_SUPERIMPOSED			(10)
#define DLM_FUNCTION_PROFILE_FILTER					(11)

#define DLM_FUNCTION_SERVO_EVENT					(16)
#define DLM_FUNCTION_SERVO							(17)
#define DLM_FUNCTION_SERVO_SUPERIMPOSED				(18)
#define DLM_FUNCTION_SERVO_FILTER					(19)

#define DLM_LOAD_MODE_NONE							(0)
#define DLM_LOAD_MODE_COMMAND						(1)
#define DLM_LOAD_MODE_BOOT							(2)
#define DLM_LOAD_MODE_RUN							(3)

typedef struct TDlmStatus
{
	long version;
	long date;
	short enable;
	long function;
} TDlmStatus;

typedef struct TDlmFunction
{
	short function;
	short enable;
	long value;
} TDlmFunction;

GT_API GT_LoadDlm(long vender,long module,char *fileName,short *pId);
GT_API GT_ProgramDlm(short id,short loadMode);
GT_API GT_GetDlmLoadMode(short id,short *pLoadMode);
GT_API GT_RunDlm(short id);
GT_API GT_StopDlm(short id);
GT_API GT_GetDlmStatus(short id,TDlmStatus *pStatus);
GT_API GT_SetDlmFunction(short id,TDlmFunction *pFunction);
GT_API GT_GetDlmFunction(short id,TDlmFunction *pFunction);

GT_API GT_DlmCommandInit(short code,long index);
GT_API GT_DlmCommandAdd16(short value);
GT_API GT_DlmCommandAdd32(long value);
GT_API GT_DlmCommandAddFloat(float value);
GT_API GT_DlmCommandAddDouble(double value);
GT_API GT_SendDlmCommand(short id,short *pReturnValue);
GT_API GT_DlmCommandGet16(short *pValue);
GT_API GT_DlmCommandGet32(long *pValue);
GT_API GT_DlmCommandGetFloat(float *pValue);
GT_API GT_DlmCommandGetDouble(double *pValue);

GT_API GTN_LoadDlm(short core,long vender,long module,char *fileName,short *pId);
GT_API GTN_ProgramDlm(short core,short id,short loadMode);
GT_API GTN_GetDlmLoadMode(short core,short id,short *pLoadMode);
GT_API GTN_RunDlm(short core,short id);
GT_API GTN_StopDlm(short core,short id);
GT_API GTN_GetDlmStatus(short core,short id,TDlmStatus *pStatus);
GT_API GTN_SetDlmFunction(short core,short id,TDlmFunction *pFunction);
GT_API GTN_GetDlmFunction(short core,short id,TDlmFunction *pFunction);

GT_API GTN_DlmCommandInit(short core,short code,long index);
GT_API GTN_DlmCommandAdd16(short core,short value);
GT_API GTN_DlmCommandAdd32(short core,long value);
GT_API GTN_DlmCommandAddFloat(short core,float value);
GT_API GTN_DlmCommandAddDouble(short core,double value);
GT_API GTN_SendDlmCommand(short core,short id,short *pReturnValue);
GT_API GTN_DlmCommandGet16(short core,short *pValue);
GT_API GTN_DlmCommandGet32(short core,long *pValue);
GT_API GTN_DlmCommandGetFloat(short core,float *pValue);
GT_API GTN_DlmCommandGetDouble(short core,double *pValue);
/*-----------------------------------------------------------*/
/* Event-Task                                                */
/*-----------------------------------------------------------*/
#define TASK_SET_DO_BIT							(0x1101)
#define TASK_SET_DAC							(0x1120)

#define TASK_STOP								(0x1303)

#define TASK_TRIGGER_CALLBACK_FUNCTION           (0x119c)

#define TASK_UPDATE_POS							(0x2002)
#define TASK_UPDATE_VEL							(0x2004)
#define TASK_UPDATE_DISTANCE					(0x2022)

#define TASK_PT_START							(0x2306)
#define TASK_PVT_START							(0x2346)
#define TASK_MOVE_ABSOLUTE						(0x2500)

#define TASK_GEAR_START							(0x3005)

#define TASK_FOLLOW_START						(0x310A)
#define TASK_FOLLOW_SWITCH						(0x310B)

#define TASK_CRD_START							(0x4004)
#define TASK_CRD_OVERRIDE						(0x4006)
#define TASK_SCAN_START							(0x4102)

#define TASK_MOVE_ESCAPE						(0x5000)

#define TASK_SET_DO_BIT_MODE_NONE				(0)
#define TASK_SET_DO_BIT_MODE_TIME				(10)
#define TASK_SET_DO_BIT_MODE_DISTANCE			(20)

//�����˿ر��������Լ����������������
#define TASK_SAVE_MC_VAR_MAX                    (5)
#define TASK_SAVE_MC_VAR                        (50)

typedef struct
{
	unsigned short type;
	unsigned short index;
	unsigned short id;
} TWatchVar;

typedef struct
{
	short doType;
	short doIndex;
	short doValue;
	short mode;
	long parameter[8];
} TTaskSetDoBit;

typedef struct
{
	short dac;
	short value;
} TTaskSetDac;

typedef struct
{
	long mask;
	long option;
} TTaskStop;

typedef struct
{
	short type;
	short index;
	short operation;
	short data[20];
} TTaskFifoOperation;

typedef struct
{
	short profile;
	long pos;
} TTaskUpdatePos;

typedef struct
{
	short profile;
	short triggerIndex;
	long distance;
} TTaskUpdateDistance;

typedef struct
{
	short profile;
	double vel;
} TTaskUpdateVel;

typedef struct
{
	long mask;
	long option;
} TTaskPtStart;

typedef struct
{
	long mask;
} TTaskPvtStart;

typedef struct
{
	long mask;
} TTaskGearStart;

typedef struct
{
	long mask;
	long option;
} TTaskFollowStart;

typedef struct
{
	long mask;
} TTaskFollowSwitch;

typedef struct
{
	short profile;
	long pos;
	double vel;
	double acc;
	double dec;
	short percent;
} TTaskMoveAbsolute;

typedef struct
{
	short mask;
	short option;
} TTaskCrdStart;

typedef struct
{
	short crd;
	double synVelOverride;
} TTaskCrdOverride;

typedef struct
{
	short port;
	short index;
	short count;
} TTaskScanStart;

typedef struct  
{
	short option;
	short reserve;
}TTaskTriggerCallbackFunction;

typedef struct
{
	short count;
	TWatchVar var[TASK_SAVE_MC_VAR_MAX];
}TTaskSaveMcVar;

typedef struct
{
	unsigned long loop;
	TWatchVar var;
	unsigned short condition;
	double value;
} TEvent;

GT_API GT_ClearEvent(void);
GT_API GT_ClearTask(void);
GT_API GT_ClearEventTaskLink(void);
GT_API GT_AddEvent(TEvent *pEvent,short *pEventIndex);
GT_API GT_AddTask(short taskType,void *pTaskData,short *pTaskIndex);
GT_API GT_AddEventTaskLink(short eventIndex,short taskIndex,short *pLinkIndex);
GT_API GT_GetEventCount(short *pCount);
GT_API GT_GetEvent(short eventIndex,TEvent *pEvent);
GT_API GT_GetEventLoop(short eventIndex,unsigned long *pCount);
GT_API GT_GetTaskCount(short *pCount);
GT_API GT_GetTask(short taskIndex,short *pTaskType,void *pTaskData);
GT_API GT_GetEventTaskLinkCount(short *pCount);
GT_API GT_GetEventTaskLink(short linkIndex,short *pEventIndex,short *pTaskIndex);
GT_API GT_EventOn(short eventIndex,short count);
GT_API GT_EventOff(short eventIndex,short count);

GT_API GTN_ClearEvent(short core);
GT_API GTN_ClearTask(short core);
GT_API GTN_ClearEventTaskLink(short core);
GT_API GTN_DeleteEvent(short core,short eventIndex);
GT_API GTN_DeleteTask(short core,short taskIndex);
GT_API GTN_DeleteEventTaskLink(short core,short linkIndex);
GT_API GTN_AddEvent(short core,TEvent *pEvent,short *pEventIndex);
GT_API GTN_AddTask(short core,short taskType,void *pTaskData,short *pTaskIndex);
GT_API GTN_AddEventTaskLink(short core,short eventIndex,short taskIndex,short *pLinkIndex);
GT_API GTN_SetEvent(short core,TEvent *pEvent,short eventIndex);
GT_API GTN_SetTask(short core,short taskType,void *pTaskData,short taskIndex);
GT_API GTN_SetEventTaskLink(short core,short eventIndex,short taskIndex,short linkIndex);
GT_API GTN_GetEventCount(short core,short *pCount);
GT_API GTN_GetEvent(short core,short eventIndex,TEvent *pEvent);
GT_API GTN_GetEventLoop(short core,short eventIndex,unsigned long *pEventLoop);
GT_API GTN_GetTaskCount(short core,short *pCount);
GT_API GTN_GetTask(short core,short taskIndex,short *pTaskType,void *pTaskData);
GT_API GTN_GetEventTaskLinkCount(short core,short *pCount);
GT_API GTN_GetEventTaskLink(short core,short linkIndex,short *pEventIndex,short *pTaskIndex);
GT_API GTN_EventOn(short core,short eventIndex,short count);
GT_API GTN_EventOff(short core,short eventIndex,short count);
GT_API GTN_GetTaskSaveMcVarResult(short core,short taskIndex,TWatchVar *pVar,double *pValue,short count,short *pReadCount);

/*--------- -------------------------------------------------*/
/* Gantry                                                    */
/*-----------------------------------------------------------*/
#define GANTRY_MODE_NONE					 			(-1)
#define GANTRY_MODE_OPEN_LOOP_GANTRY					(1)
#define GANTRY_MODE_DECOUPLE_POSITION_LOOP				(2)
#define GANTRY_MODE_RINGNET_DRIVER						(10)

GT_API GT_SetGantryMode(short group,short master,short slave,short mode,long syncErrorLimit=1000);
GT_API GT_GetGantryMode(short group,short *pMaster,short *pSlave,short *pMode,long *pSyncErrorLimit);
GT_API GT_SetGantryPid(short group,TPid *pGantryPid,TPid *pYawPid);
GT_API GT_GetGantryPid(short group,TPid *pGantryPid,TPid *pYawPid);
GT_API GT_GantryAxisOn(short group);
GT_API GT_GantryAxisOff(short group);

GT_API GTN_SetGantryMode(short core,short group,short master,short slave,short mode,long syncErrorLimit=1000);
GT_API GTN_GetGantryMode(short core,short group,short *pMaster,short *pSlave,short *pMode,long *pSyncErrorLimit);
GT_API GTN_SetGantryPid(short core,short group,TPid *pGantryPid,TPid *pYawPid);
GT_API GTN_GetGantryPid(short core,short group,TPid *pGantryPid,TPid *pYawPid);
GT_API GTN_GantryAxisOn(short core,short group);
GT_API GTN_GantryAxisOff(short core,short group);

typedef struct SecondOrderFilterPara
{
	short active;

	double a0;
	double a1;
	double a2;

	double b1;
	double b2;

} TSecondOrderFilterPara;

#define TYPE_CONTROL_OUTPUT_FILTER			(1)
#define TYPE_YAW_CONTROL_OUTPUT_FILTER		(2)
#define FILTER_COUNT_MAX					(2)

GT_API GT_SetSecondOrderFilterPara(short control,short type,short index,TSecondOrderFilterPara *pFilterPrm);
GT_API GT_GetSecondOrderFilterPara(short control,short type,short index,TSecondOrderFilterPara *pFilterPrm);

GT_API GTN_SetSecondOrderFilterPara(short core,short control,short type,short index,TSecondOrderFilterPara *pFilterPrm);
GT_API GTN_GetSecondOrderFilterPara(short core,short control,short type,short index,TSecondOrderFilterPara *pFilterPrm);

typedef struct _OCA_CTRL_GEN_
{
	short  s16Gain;
	short  s16Offset;
	double dFrq;
	long   u32RunPeriod;
	short  u16SigType;
} OCA_CTRL_GEN;

typedef struct ExcitationPara
{
	short gain;
	short offset;
	short frq;		// hz
	double runTime;	// s
} TExcitationPara;

typedef struct ExcitationTrapPara
{
	double vel;
	double acc;
	double dec;
	double runTime;	// s
} TExcitationTrpPara;

#define NO_EXCIT						(0xff)
#define OPEN_LOOP_EXCIT					(1)
#define SIGNAL_TYPE_STEP				(3)
#define SIGNAL_TYPE_SIN					(0x10)
#define SIGNAL_TYPE_TRAP				(0x11)
#define SIGNAL_TYPE_NOTHING				(0xFF)


GT_API GT_SetGenerator(OCA_CTRL_GEN *pGenStr);
GT_API GT_GetGenerator(OCA_CTRL_GEN *pGenStr);
GT_API GT_StepResponse(short control,short gain, double time);
GT_API GT_SetExctLoopMode(short control,short exciteLoopMode);
GT_API GT_GetExctLoopMode(short control,short *pExciteLoopMode);
GT_API GT_SetExcitation(short axis,short object,short type,void * pParameter);

GT_API GTN_SetGenerator(short core,OCA_CTRL_GEN *pGenStr);
GT_API GTN_StepResponse(short core,short control,short gain,double time);
GT_API GTN_SetExctLoopMode(short core,short control,short exciteLoopMode);
GT_API GTN_GetExctLoopMode(short core,short control,short *pExciteLoopMode);


/*-----------------------------------------------------------*/
/* DMA                                                       */
/*-----------------------------------------------------------*/
GT_API GT_CrdHsOn(short crd,short fifo,short link=1,unsigned short threshold=200,short lookAheadInMc=0);
GT_API GT_CrdHsOff(short crd,short fifo);

GT_API GTN_CrdHsOn(short core,short crd,short fifo,short dmaBuf=1,unsigned short threshold=200,short lookAheadInMc=0);
GT_API GTN_CrdHsOff(short core,short crd,short fifo);

/*-----------------------------------------------------------*/
/* Others                                                    */
/*-----------------------------------------------------------*/
GT_API GTN_SetRetainValue(short core,unsigned long address,short count,short *pData);
GT_API GTN_GetRetainValue(short core,unsigned long address,short count,short *pData);

GT_API GTN_SetGPIOConfig(short core,short station,long effectiveLevel,long direction);
GT_API GTN_SetPrfTorque(short core,short axis,short prfTorque);
GT_API GTN_GetAtlTorque(short core,short axis,short *atlTorque);
GT_API GTN_PosCurrFeedForward(short core,short profile,double pos,long gtime,short torque,short gtype,short fifo=0);
GT_API GTN_SetMotionMode(short core,short axis,short motionMode);
GT_API GTN_GetMotionMode(short core,short axis,short *motionMode);

GT_API GTN_SetProfileTime(short core,long profileTime,long delay,long stepCoef);
GT_API GTN_GetProfileTime(short core,long *pProfileTime,long *pDelay,long *pStepCoef);
GT_API GTN_SetCoreTime(short core,long profileTime,long delay,long stepCoef);
GT_API GTN_GetCoreTime(short core,long *pProfileTime,long *pDelay,long *pStepCoef);
GT_API GTN_SetCorePeriod(short core,double period);
GT_API GTN_GetCorePeriod(short core,double *pPeriod,short *pFlag,short *pInfo);
typedef struct ControlInfo
{
	double refPos;
	double refPosFilter;
	double refPosFilter2;
	double cntPos;
	double cntPosFilter;

	double error;
	double refVel;
	double refAcc;

	short value;
	short valueFilter;

	short offset;
} TControlInfo;

typedef struct
{
	unsigned long notify;
	unsigned long receive;
	unsigned long execute;
	unsigned long retry;
	unsigned long receiveError;
	unsigned long echo;
} TCommandCount;

GT_API GT_ClearCommandCount(void);
GT_API GT_GetCommandCount(TCommandCount *pCommandCount);
GT_API GT_SetServoTime(long servoTime,long delay,long stepCoef);
GT_API GT_GetServoTime(long *pServoTime,long *pDelay,long *pStepCoef);
GT_API GT_GetControlInfo(short control,TControlInfo *pControlInfo);

GT_API GTN_ClearCommandCount(short core);
GT_API GTN_GetCommandCount(short core,TCommandCount *pCommandCount);
GT_API GTN_SetServoTime(short core,long servoTime,long delay,long stepCoef);
GT_API GTN_GetServoTime(short core,long *pServoTime,long *pDelay,long *pStepCoef);
GT_API GTN_GetControlInfo(short core,short control,TControlInfo *pControlInfo);

GT_API GT_SetLongVar(short index,long value);
GT_API GT_GetLongVar(short index,long *pValue);
GT_API GT_SetDoubleVar(short index,double value);
GT_API GT_GetDoubleVar(short index,double *pValue);

GT_API GT_GetBufWaitDiStatus(short crd,short *pDiType,unsigned short *pDiIndex,unsigned short *pLevel, short *pContinueTime,long *pOverTime,short *pFlagMode,long *pSegNum,short *pEnable,long *pCount,short fifo);
GT_API GT_GetBufWaitLongVarStatus(short crd,short *pIndex,long *pValue,short *pFlagMode,long *pSegNum,short *pEnable,short *pStatus,short fifo);
GT_API GT_ClearBufWaitStatus(short crd,short fifo);

GT_API GT_BufWaitDi(short crd, short diType, unsigned short diIndex,unsigned short level, short continueTime, long overTime, short flagMode,long segNum, short fifo);
GT_API GT_BufWaitLongVar(short crd, short index, long value, long overTime, short flagMode, long segNum, short fifo);

GT_API GTN_SetLongVar(short core,short index,long value);
GT_API GTN_GetLongVar(short core,short index,long *pValue);
GT_API GTN_SetDoubleVar(short core,short index,double value);
GT_API GTN_GetDoubleVar(short core,short index,double *pValue);

GT_API GTN_GetBufWaitDiStatus(short core,short crd,short *pDiType,unsigned short *pDiIndex,unsigned short *pLevel, short *pContinueTime,long *pOverTime,short *pFlagMode,long *pSegNum,short *pEnable,long *pCount,short fifo);
GT_API GTN_GetBufWaitLongVarStatus(short core,short crd,short *pIndex,long *pValue,short *pFlagMode,long *pSegNum,short *pEnable,short *pStatus,short fifo);
GT_API GTN_ClearBufWaitStatus(short core,short crd,short fifo);
GT_API GTN_BufWaitDi(short core,short crd, short diType, unsigned short diIndex,unsigned short level, short continueTime, long overTime, short flagMode,long segNum, short fifo);
GT_API GTN_BufWaitLongVar(short core,short crd, short index,long value,long overTime,short flagMode,long segNum,short fifo);


GT_API GT_SetAxisMotionSmooth(short axis,double time,double k);
GT_API GT_GetAxisMotionSmooth(short axis,double *pTime,double *pK);
GT_API GTN_SetAxisMotionSmooth(short core,short axis,double time,double k);
GT_API GTN_GetAxisMotionSmooth(short core,short axis,double *pTime,double *pK);

GT_API GT_BufDoBit(short crd,unsigned short doType,unsigned short index,short value,short fifo);
GT_API GTN_BufDoBit(short core,short crd,unsigned short doType,unsigned short index,short value,short fifo);
GT_API GTN_BufDoBitDelay(short core,short crd,unsigned short doType,unsigned short index,short value,long delayTime,short fifo);

GT_API GT_SetCrdJerk(short crd,double jerkMax);
GT_API GT_GetCrdJerk(short crd,double *pJerkMax);
GT_API GTN_SetCrdJerk(short core,short crd,double jerkMax);
GT_API GTN_GetCrdJerk(short core,short crd,double *pJerkMax);
GT_API GT_SetCrdJerkTime(short crd,double jerkTime,double coef);
GT_API GT_GetCrdJerkTime(short crd,double *pJerkTime,double *pCoef);
GT_API GTN_SetCrdJerkTime(short core,short crd,double jerkTime,double coef);
GT_API GTN_GetCrdJerkTime(short core,short crd,double *pJerkTime,double *pCoef);
typedef struct
{
	short percent;
	short accStartPercent;
	short decEndPercent;
	double reserve;
} TCrdSmooth;
GT_API GT_SetCrdSmooth(short crd,TCrdSmooth *pCrdSmooth);
GT_API GT_GetCrdSmooth(short crd,TCrdSmooth *pCrdSmooth);
GT_API GT_SetCrdSmoothTime(short crd,short smoothType,double *pPrm);
GT_API GT_GetCrdSmoothTime(short crd,short *pSmoothType,double *pPrm);
GT_API GTN_SetCrdSmooth(short core,short crd,TCrdSmooth *pCrdSmooth);
GT_API GTN_GetCrdSmooth(short core,short crd,TCrdSmooth *pCrdSmooth);
GT_API GTN_SetCrdSmoothTime(short core,short crd,short smoothType,double *pPrm);
GT_API GTN_GetCrdSmoothTime(short core,short crd,short *pSmoothType,double *pPrm);

//////////////////////////////////////////////////////////////////////////
//Standard Home
//////////////////////////////////////////////////////////////////////////

#define STANDARD_HOME_STAGE_IDLE              (0)   //δ������ԭ��
#define STANDARD_HOME_STAGE_START             (1)   //������ԭ��
#define HOME_STAGE_ON_HOME_LIMIT_ESCAPE		  (2)
#define STANDARD_HOME_STAGE_SEARCH_HOME       (20)  //��������Home
#define STANDARD_HOME_STAGE_SEARCH_INDEX      (30)  //��������Index
#define STANDARD_HOME_STAGE_GO_HOME           (80)  //�����˶���ԭ��
#define STANDARD_HOME_STAGE_END               (100) //��ԭ�����
#define STANDARD_HOME_STAGE_START_CHECK       (-1)  //������ԭ��ǰ�Լ�
#define STANDARD_HOME_STAGE_CHECKING          (-2)  //�Լ���

#define STANDARD_HOME_ERROR_NONE		      (0)   //δ��������
#define STANDARD_HOME_ERROR_DISABLE	          (10)  //ִ�л�ԭ�����δʹ��
#define STANDARD_HOME_ERROR_ALARM		      (20)  //ִ�л�ԭ����ᱨ��
#define STANDARD_HOME_ERROR_STOP		      (30)  //δ��ɻ�ԭ�㣬��ֹͣ�˶�
#define STANDARD_HOME_ERROR_ON_LIMIT          (40)  //��������λ�޷�����
#define STANDARD_HOME_ERROR_NO_HOME	          (50)  //δ�ҵ�Home
#define STANDARD_HOME_ERROR_NO_INDEX          (60)  //δ�ҵ�Index
#define STANDARD_HOME_ERROR_NO_LIMIT          (70)  //δ�ҵ���λ
#define STANDARD_HOME_ERROR_ENCODER_DIR_SCALE (-1)  //�滮����������������෴���ߵ�����һ��


typedef struct
{
	short mode;		      // ��ԭ��ģʽȡֵ��Χ1~36
	double highSpeed;     // ����Home���ٶȣ���λpulse/ms
	double lowSpeed;	  // ����Index���ٶȣ���λpulse/ms
	double acc;		      // ������ٶȣ���λpulse/ms^2
	long offset;          // ����ƫ��������λpulse
	short check;          // �Ƿ������Լ칦�ܣ�1-���ã�����ֵ-������
	short autoZeroPos;    // ��������Ƿ��Զ����㣬1-�Զ����㣬����ֵ-������
	long motorStopDelay;  //�����λ��ʱ����λ����������
	short pad1[3];	      // ����������Ҫ���ã�
} TStandardHomePrm;

typedef struct
{
	short run;           // �����ڽ��л�ԭ�㣬0����ֹͣ�˶���1-���ڻ�ԭ��
	short stage;         // ��ԭ���˶��Ľ׶�
	short error;         // ��ԭ����̵ķ����Ĵ���
	short pad1[3];       // �������޾��庬�壩
	long capturePos;     // ����Home��Indexʱ�̵ı�����λ��
	long targetPos;      // ��Ҫ�˶�����Ŀ��λ�ã�ԭ��λ�û���ԭ��λ��+ƫ��������������Limitʱ��������Home��Indexʱ�����õ���������Ϊ0����ô��ֵ��ʾΪ805306368
} TStandardHomeStatus;

GT_API GT_ExecuteStandardHome(short axis,TStandardHomePrm *pHomePrm);
GT_API GT_GetStandardHomePrm(short axis,TStandardHomePrm *pHomePrm);
GT_API GT_GetStandardHomeStatus(short axis,TStandardHomeStatus *pHomeStatus);

GT_API GTN_ExecuteStandardHome(short core,short axis,TStandardHomePrm *pHomePrm);
GT_API GTN_GetStandardHomePrm(short core,short axis,TStandardHomePrm *pHomePrm);
GT_API GTN_GetStandardHomeStatus(short core,short axis,TStandardHomeStatus *pHomeStatus);

typedef struct
{
	unsigned long onCount;
	unsigned long offCount;
	unsigned long onCountInFpga;
	unsigned long offCountInFpga;
	unsigned long pad[4];
}TLaserOnOffCount;

GT_API GTN_GetLaserOnOffCount(short core,short channel,TLaserOnOffCount *pLaserCount);
GT_API GTN_ClearLaserOnOffCount(short core,short channel);

GT_API GT_SetAxisInputShaping(short axis,short enable,short count,double k);
GT_API GTN_SetAxisInputShaping(short core,short axis,short enable,short count,double k);

GT_API GT_SetGantrySynchErrorCompensate2DTable(short tableIndex,TCompensate2DTable *pTable,long *pData,short extend);
GT_API GT_GetGantrySynchErrorCompensate2DTable(short tableIndex,TCompensate2DTable *pTable,short *pExtend);
GT_API GT_SetGantrySynchErrorCompensate2D(short group,TCompensate2D *pComp2d);
GT_API GT_GetGantrySynchErrorCompensate2D(short group,TCompensate2D *pComp2d);
GT_API GT_GetGantrySynchErrorCompensate2DValue(short group,double *pValue);
GT_API GTN_SetGantrySynchErrorCompensate2DTable(short core,short tableIndex,TCompensate2DTable *pTable,long *pData,short extend);
GT_API GTN_SetGantrySynchErrorCompensate2D(short core,short group,TCompensate2D *pComp2d);

typedef struct
{
	short type;
	short enable;
	short flagMode;
	short diType;
	short diIndex;
	short diValue;
	unsigned short continueTime;
	unsigned short trigDelay;
	unsigned long overTime;
	unsigned long counter;
	long longVar;
	long segNum;
	short stop;
	short overTimeStop;
	short pad1[2];
}TBufWaitDiStatusEx;
GT_API GTN_GetBufWaitDiStatusEx(short core,short crd,short fifo,TBufWaitDiStatusEx *pStatus);

GT_API GTN_SetPosCompareFifoMode(short core,short index,short mode);
GT_API GTN_GetPosCompareFifoMode(short core,short index,short *pMode);
GT_API GTN_GetPosCompareLatchValue(short core,short index,long count,long *pDataX,long *pDataY,long *pCount,TLatchValueInfo *pInfo);


typedef struct
{
	unsigned long profileMask;
	long offset;
	double vel;
	double acc;
}TTaskMoveEscape;

typedef struct
{
	short eventHit;
	short pad1[3];
	long pad2[2];
	double pad3[2];
}TEventStatus;

typedef struct
{
	short start;
	short execute;
	short pad1[2];
	long pad2[2];
	double pad3[2];
}TaskStatus;

GT_API GTN_GetEventStatus(short core,short index,TEventStatus *pStatus);
GT_API GTN_GetTaskStatus(short core,short index,TaskStatus *pStatus);
GT_API GTN_SetTriggerMoveEscape(short core,short trigger,TTaskMoveEscape *pPrm);

GT_API GTN_GetCrdHsPrm(short core,short crd,short fifo,short *pEnable,short *pLink,unsigned short *pThreshold,short *pLookAheadInMc);

GT_API GTN_SetPrfPosEx(short core,short profile,double pos);
GT_API GTN_SetEncPosEx(short core,short encoder,double pos);
GT_API GTN_GetDiBit(short core,short diType,short diIndex,short *pValue);
typedef struct
{
	double pos;
	double vel;
	double reserve[2];
	long di;
	long reserve1[3];
}TMpgInfo;
GT_API GTN_ReadMpgInfo(short core,short mpg,TMpgInfo *pMpgInfo);
GT_API GTN_WriteMpgPos(short core,short mpg,double *pPos,short count=1);
GT_API GTN_ReadAuEncPos(short core,short encoder,double *pPos,short count=1);
GT_API GTN_WriteAuEncPos(short core,short encoder,double *pPos,short count=1);
GT_API GTN_ClearMcStatus(short core);
GT_API GTN_SetMcInfo(short core,long info,long index,unsigned long data);
GT_API GTN_GetMcInfo(short core,long info,long index,unsigned long *pData);
GT_API GTN_GetRNMasterInfo(short core,unsigned short *pPhyId,unsigned short *pType,unsigned short *pInfo);
GT_API GTN_SetRNMasterInfo(short core,unsigned short phyId,unsigned short type,unsigned short info);
GT_API GTN_RN_MltPcPduRd(short core,unsigned char* pData, unsigned char des_id,unsigned short byte_start_offset,unsigned short byte_num);
GT_API GTN_RN_MltPcPduRdUpdate(short core,unsigned char des_id);
GT_API GTN_RN_MltPcPduWr(short core,unsigned char* pData, unsigned char des_id, unsigned short byte_start_offset,unsigned short byte_num);
GT_API GTN_RN_MltPcPduWrUpdate(short core,unsigned char des_id);

typedef struct
{
	short run;
	short mode;
	double power;
	double frequency;
	double pulseWidth;
	double pad1[9];
	short pad2[8];
} TLaserStatus;
GT_API GTN_GetLaserStatus(short core,short channel,TLaserStatus *pStatus);

typedef struct
{
	short list;
	short reserve1[2];
	short modal;
	long segNum;
	long reserve2[3];
	double reserve3[4];
}TListInfo;

typedef struct
{
	short execute;
	short empty;
	short stopInfo;
	short reserve1;
	short motionDone;
	short commandType;
	short command;
	short direction;
	long executeSegNum;
	long remainderSegCount;
	long reserve2[6];
} TCommandListStatus;

typedef struct
{
	short mode;
	short elementSize;
	short reserve1[6];
	long forwardSpace;
	long reverseSpace;
	long reserve2[6];
} TCommandListConfig;

GT_API GTN_GetCommandListSpace(short core,short list,long *pSpace);
GT_API GTN_GetCommandListStatus(short core,short list,TCommandListStatus *pStatus);
GT_API GTN_ClearCommandListData(short core,short list,TListInfo *pListInfo=NULL);
GT_API GTN_CommandListDataEnd(short core,short list);
GT_API GTN_StartCommandList(short core,short list,TListInfo *pListInfo=NULL);
GT_API GTN_StartMultiCommandList(short core,unsigned long mask,TListInfo *pListInfo=NULL);
GT_API GTN_StopCommandList(short core,short index,short stopMode,TListInfo *pListInfo=NULL);
GT_API GTN_StopMultiCommandList(short core,unsigned long mask,short stopMode,TListInfo *pListInfo=NULL);

#define WAIT_TIMEOUT_MODE_INFINITY          (0)
#define WAIT_TIMEOUT_MODE_SKIP              (1)
#define WAIT_TIMEOUT_MODE_STOP              (2)

typedef struct
{
	TWatchVar var;
	unsigned short condition;
	double value;
} TWatchCondition;

typedef struct
{
	unsigned short operation;
	unsigned short varType;
	unsigned short result;
	unsigned short lhs;
	unsigned short rhs;
} TVarCalculate;

typedef struct
{
	short varIndex;
	short reserve[3];
	TWatchCondition watchCondition;
} TVarCondition;

typedef struct
{
	long time;				// ��ʱʱ��
	short mode;		        // ��ʱ�����Ϊ��0�����޵ȴ���1��������ǰ�ȴ���������ִ��ָ������2��ָֹͣ����
	short reserve1;
	double reserve2[4];
} TWaitTimeout;

GT_API GTN_SetVarBoolCondition(short core,short varIndex,TWatchCondition *pWatchCondition);
GT_API GTN_LoadVarCalculate(short core,TVarCalculate *pVarCalculate,short count,TListInfo *pListInfo=NULL);
GT_API GTN_MoveTrap(short core,short profile,double pos,double vel,TTrapPrm *pPrm,TListInfo *pList=NULL);
GT_API GTN_SetVarCondition(short core,short varIndex,TWatchCondition *pWatchCondition,short conditionCount,short operation,TListInfo *pListInfo);
GT_API GTN_WaitForCondition(short core,TWatchCondition *pWatchCondition,short conditionCount,short operation,TWaitTimeout *pTimeout,TListInfo *pListInfo=NULL);
GT_API GTN_GetWaitForCondition(short core,short list,TWatchCondition *pWatchCondition,short *pConditionCount,short *pOperation,TWaitTimeout *pTimeout,short *pConditionResult,short *pConditionDone);

#define DIGITAL_OUTPUT_MODE_NORMAL                    (0)
#define DIGITAL_OUTPUT_MODE_REVERSE_TIME              (10)

typedef struct
{
	double time;
	double reserve[9];
}TDoReverseParameter;

typedef union
{
	TDoReverseParameter doReverse;
	double data[10];
}TDigitalOutputMode;

typedef struct
{
	short mode;              //Do���ģʽ
	short doType;
	short doIndex;
	short doValue;
	short reverse1[4];
	long  reserve2[2];
	TDigitalOutputMode prm;
}TDigitalOutputBit;

typedef struct
{
	double delayTime;
	short reserve1[4];
	long reserve2[2];
	double reserve3[2];
}TDelay;

GT_API GTN_WriteDigitalOutputBit(short core,TDigitalOutputBit *pDoBit,TListInfo *pListInfo=NULL);
GT_API GTN_SetDelay(short core,TDelay *pDelay,TListInfo *pListInfo);


typedef struct
{
	short  count;
	short  reverse1[3];
	double alpha[4];
	double beta[4];
}TProfileScale;
GT_API GTN_SetAxisScale(short core,short profile,TProfileScale *pScale,TListInfo *pListInfo=NULL);
GT_API GTN_GetAxisScale(short core,short profile,TProfileScale *pScale);

GT_API GTN_GetTrapSts(short core,short profile,short *prfsts);
GT_API GTN_ClearTrapSts(short core,short profile);

GT_API GTN_SetMcMode(short core,short mode,short value);
GT_API GTN_GetMcMode(short core,short mode,short *pValue);

/*-----------------------------------------------------------*/
/* New Watch  Code                                           */
/*-----------------------------------------------------------*/
#define WATCH_GROUP_TIMER					(0)
#define WATCH_GROUP_BACKGROUND				(1)

#define WATCH_MODE_STATIC					(0)
#define WATCH_MODE_LOOP						(1)
#define WATCH_MODE_DYNAMIC					(2)

#define WATCH_EVENT_MAX						(8)

#define WATCH_EVENT_RUN						(1)
#define WATCH_EVENT_START					(10)
#define WATCH_EVENT_STOP					(20)
#define WATCH_EVENT_OFF						(30)

#define WATCH_CONDITION_NONE				(0)

#define WATCH_CONDITION_EQ					(1)
#define WATCH_CONDITION_NE					(2)
#define WATCH_CONDITION_GE					(3)
#define WATCH_CONDITION_LE					(4)

#define WATCH_CONDITION_CHANGE_TO			(11)
#define WATCH_CONDITION_CHANGE				(12)
#define WATCH_CONDITION_UP					(13)
#define WATCH_CONDITION_DOWN				(14)
#define WATCH_CONDITION_CHANGE_BEYOND		(15)
#define WATCH_CONDITION_CHANGE_MAX			(16)

#define WATCH_CONDITION_REMAIN_AT			(21)
#define WATCH_CONDITION_REMAIN				(22)
#define WATCH_CONDITION_CROSS_POSITIVE		(23)
#define WATCH_CONDITION_CROSS_NEGATIVE		(24)

#define WATCH_CONDITION_NEAREST				(31)
#define WATCH_CONDITION_DELTA				(32)


#define WATCH_VAR_NONE						(0)

#define WATCH_VAR_UUID						(1000)

#define WATCH_VAR_POWER_ON_COUNT			(1060)

#define WATCH_VAR_DSP_PROGRAM_COUNT			(1070)

#define WATCH_VAR_DSP_TEMPERATURE			(1072)

#define WATCH_VAR_FPGA_PROGRAM_COUNT		(1080)

#define WATCH_VAR_CLOCK						(1200)
#define WATCH_VAR_PRF_LOOP					(1201)
#define WATCH_VAR_PRF_PERIOD				(1205)
#define WATCH_VAR_PRF_TIME					(1206)

#define WATCH_VAR_SKIP_MODULE				(1211)
#define WATCH_VAR_TEST_MODE					(1212)

#define WATCH_VAR_COMMAND_CODE				(1220)
#define WATCH_VAR_COMMAND_DATA				(1221)
#define WATCH_VAR_COMMAND_COUNT				(1222)
#define WATCH_VAR_COMMAND_READ_FLAG			(1223)

#define WATCH_VAR_LINK_PORT_TX_USE			(1660)
#define WATCH_VAR_LINK_PORT_TX_REQUIRE		(1661)
#define WATCH_VAR_LINKPORT_TX_STATUS		(1662)
#define WATCH_VAR_LINKPORT_TX_ERROR_COUNT	(1663)
#define WATCH_VAR_LINKPORT_TX_SKIP_MAX		(1664)

#define WATCH_VAR_SPORT_STATUS				(1682)
#define WATCH_VAR_SPORT_ERROR_COUNT			(1683)


#define WATCH_VAR_PRF_POS					(6000)
#define WATCH_VAR_PRF_VEL					(6001)
#define WATCH_VAR_PRF_ACC					(6002)
#define WATCH_VAR_PRF_POS_RAW				(6003)
#define WATCH_VAR_PRF_VEL_RAW				(6004)

#define WATCH_VAR_PRF_VEL_F32				(6011)
#define WATCH_VAR_PRF_ACC_F32				(6012)
#define WATCH_VAR_PRF_JERK_F32				(6013)

#define WATCH_VAR_PRF_VEL_64				(6021)

#define WATCH_VAR_PRF_RUN					(6200)
#define WATCH_VAR_LIMIT_POSITIVE_STATUS     (6201)
#define WATCH_VAR_LIMIT_NEGATIVE_STATUS     (6202)

// 6600 Trap

#define WATCH_VAR_PT_PRF_POS_F64			(6650)
#define WATCH_VAR_PT_SPACE					(6660)
#define WATCH_VAR_PT_RECEIVE				(6662)
#define WATCH_VAR_PT_EXECUTE				(6663)

#define WATCH_VAR_TRAP_TOTAL_TIME           (6670)
#define WATCH_VAR_TRAP_REMAIN_TIME          (6671)

// 6700 PVT

// 6750 Follow

// 7000 MoveAbsolute
#define WATCH_VAR_MOVE_ABSOLUTE_DONE		(7008)

// 7050 MoveVelocity
#define WATCH_VAR_MOVE_VELOCITY_IN_VELOCITY	(7058)

#define WATCH_VAR_CRD_PRF_POS				(8000)
#define WATCH_VAR_CRD_PRF_VEL				(8001)
#define WATCH_VAR_CRD_PRF_ACC				(8002)
#define WATCH_VAR_CRD_PRF_VEL_RAW			(8003)

#define WATCH_VAR_CRD_PRF_TEMP_DATA         (8010)

#define WATCH_VAR_CRD_RUN					(8200)

#define WATCH_VAR_CRD_SEGMENT_NUMBER		(8202)
#define WATCH_VAR_CRD_SEGMENT_NUMBER_USER	(8203)
#define WATCH_VAR_CRD_COMMAND_RECEIVE		(8204)
#define WATCH_VAR_CRD_COMMAND_EXECUTE		(8205)

#define WATCH_VAR_CRD_FOLLOW_SLAVE_POS		(8600)
#define WATCH_VAR_CRD_FOLLOW_SLAVE_VEL		(8601)

#define WATCH_VAR_CRD_FOLLOW_STAGE			(8610)

#define WATCH_VAR_CONTOUR_PEDAL_POS			(8800)
#define WATCH_VAR_CONTOUR_PRF_POS			(8801)
#define WATCH_VAR_CONTOUR_PRF_POS_SHAPING	(8802)
#define WATCH_VAR_CONTOUR_ENC_POS			(8803)
#define WATCH_VAR_CONTOUR_DAC               (8804)

#define WATCH_VAR_CONTOUR_FIFO_POINT_COUNT	(8808)
#define WATCH_VAR_CONTOUR_FIFO_POINT_MAX	(8809)

#define WATCH_VAR_LIST_EXECUTE				(9240)
#define WATCH_VAR_LIST_SEG_NUM              (9250)

#define WATCH_VAR_CATCH_UP_STATE                           (12000)
#define WATCH_VAR_CATCH_UP_COMMAND                         (12001)
#define WATCH_VAR_CATCH_UP_MASTER_POS                      (12002)
#define WATCH_VAR_CATCH_UP_MASTER_VEL                      (12003)
#define WATCH_VAR_CATCH_UP_SLAVE_POS                       (12004)
#define WATCH_VAR_CATCH_UP_SLAVE_VEL                       (12005)
#define WATCH_VAR_CATCH_UP_PIECE_POS                       (12006)
#define WATCH_VAR_CATCH_UP_PIECE_ID                        (12007)
#define WATCH_VAR_CATCH_UP_PIECE_COUNT                     (12008)
#define WATCH_VAR_CATCH_UP_PIECE_FIFO_COMMAND_RECEIVE      (12009)
#define WATCH_VAR_CATCH_UP_PIECE_FIFO_COMMAND_SEND         (12010)
#define WATCH_VAR_CATCH_UP_SYNCH_DISTANCE                  (12011)
#define WATCH_VAR_CATCH_UP_SYNCN_TIME                      (12012)
#define WATCH_VAR_CATCH_UP_PIECE_START_POS                 (12013)
#define WATCH_VAR_CATCH_UP_PIECE_SYNCH_POS                 (12014)
#define WATCH_VAR_CATCH_UP_SLAVE_START_POS                 (12015)
#define WATCH_VAR_CATCH_UP_SLAVE_SYNCH_POS                 (12016)

#define WATCH_VAR_POS_COMPARE_COMMAND_RECEIVE	(17422)
#define WATCH_VAR_POS_COMPARE_COMMAND_SEND		(17423)
#define WATCH_VAR_POS_COMPARE_COMMAND_LEFT		(17424)
#define WATCH_VAR_POS_COMPARE_COMMAND_TX		(17425)
#define WATCH_VAR_POS_COMPARE_PULSE_COUNT		(17426)
#define WATCH_VAR_POS_COMPARE_PSO_ON_OFF		(17427)
#define WATCH_VAR_POS_COMPARE_PSO_REG			(17430)
#define	WATCH_VAR_POS_COMPARE_PSO_REG_EXT		(17431)
#define	WATCH_VAR_POS_COMPARE_ENC_PSO_ON_OFF	(17432)

#define WATCH_VAR_SCAN_PRF_POS				(18000)
#define WATCH_VAR_SCAN_PRF_VEL				(18001)
#define WATCH_VAR_SCAN_PRF_ACC				(18002)

#define WATCH_VAR_SCAN_PRF_POS_X			(18010)
#define WATCH_VAR_SCAN_PRF_POS_Y			(18020)
#define WATCH_VAR_SCAN_PRF_POS_Z			(18030)

#define WATCH_VAR_SCAN_RUN					(18200)

#define WATCH_VAR_SCAN_SEGMENT_NUMBER		(18202)

#define WATCH_VAR_SCAN_COMMAND_RECEIVE		(18422)
#define WATCH_VAR_SCAN_COMMAND_SEND			(18423)
#define WATCH_VAR_SCAN_COMMAND_LEFT			(18424)
#define WATCH_VAR_SCAN_COMMAND_TX			(18425)

#define WATCH_VAR_LASER_HSIO				(18600)
#define WATCH_VAR_LASER_POWER				(18601)
#define WATCH_VAR_LASER_WORK_RATIO			(18602)

#define WATCH_VAR_AXIS_PRF_POS				(20000)
#define WATCH_VAR_AXIS_PRF_VEL				(20001)
#define WATCH_VAR_AXIS_PRF_ACC				(20002)

#define WATCH_VAR_AXIS_PRF_POS_OTHER		(20004)
#define WATCH_VAR_AXIS_PRF_VEL_OTHER		(20005)

#define WATCH_VAR_AXIS_PRF_POS_FILTER		(20010)
#define WATCH_VAR_AXIS_PRF_VEL_FILTER		(20011)

#define WATCH_VAR_AXIS_TEMP_PRF_POS_FILTER  (20012)
#define WATCH_VAR_AXIS_PRF_POS_FILTER_BEFORE_COMP (20013)

#define WATCH_VAR_AXIS_PRF_VEL_64			(20021)

#define WATCH_VAR_AXIS_STATUS		        (20100)

#define WATCH_VAR_AXIS_RUN		            (20200)

#define WATCH_VAR_AXIS_ENC_POS_FILTER		(20310)
#define WATCH_VAR_AXIS_ENC_VEL_FILTER		(20311)

#define WATCH_VAR_AXIS_ENC_VEL_64_FILTER	(20321)

#define WATCH_VAR_AXIS_PREDICTION_POS_IN    (20350)
#define WATCH_VAR_AXIS_PREDICTION_POS_IN_2  (20351)
#define WATCH_VAR_AXIS_PREDICTION_POS_OUT   (20352)

#define WATCH_VAR_AXIS_PREDICTION_VEL_IN    (20355)
#define WATCH_VAR_AXIS_PREDICTION_VEL_IN_2  (20356)
#define WATCH_VAR_AXIS_PREDICTION_VEL_OUT   (20357)

#define WATCH_VAR_AXIS_PREDICTION_OUT       (20360)
#define WATCH_VAR_AXIS_PREDICTION_FILTER_POS                    (20361)
#define WATCH_VAR_AXIS_PREDICTION_FILTER_VEL                    (20362)

#define WATCH_VAR_POSCOMPARE_PREDICTION_ENABLE                  (20370)
#define WATCH_VAR_POSCOMPARE_PREDICTION_WORK                    (20371)
#define WATCH_VAR_POSCOMPARE_PREDICTION_OUTPUT_COUNT_TOTAL      (20372)

#define WATCH_VAR_DRIVER_ACT_VEL			(20400)
#define WATCH_VAR_STIMULATE_DATA			(20401)
#define WATCH_VAR_DRIVER_CURRENT_KVFF		(20402)

#define WATCH_VAR_CONTROL_ERROR				(20500)

#define WATCH_VAR_BACKLASH_VALUE			(21000)
#define WATCH_VAR_LEADSCREW_VALUE			(21001)
#define WATCH_VAR_FRICTION_VALUE			(21003)

#define WATCH_VAR_ENC_POS					(30000)
#define WATCH_VAR_ENC_VEL					(30001)
#define WATCH_VAR_AU_ENC_POS				(30002)
#define WATCH_VAR_AU_ENC_VEL				(30003)

#define WATCH_VAR_PULSE_POS					(30010)

#define WATCH_VAR_ENC_VEL_64				(30021)
#define WATCH_VAR_AU_ENC_VEL_64				(30022)
#define WATCH_VAR_ENC_VEL_64_1MS			(30023)
#define WATCH_VAR_AU_ENC_VEL_64_1MS			(30024)

#define WATCH_VAR_MPG_INFO					(30200)
#define WATCH_VAR_AU_ENCODER_EX_POS         (30201)
#define WATCH_VAR_AU_ENCODER_EX_VEL         (30202)
#define WATCH_VAR_MPG_ENCODER_POS           (30203)
#define WATCH_VAR_MPG_ENCODER_VEL           (30204)

#define WATCH_VAR_GPI						(31000)
#define WATCH_VAR_LIMIT_POSITIVE			(31010)
#define WATCH_VAR_LIMIT_NEGATIVE			(31020)
#define WATCH_VAR_ALARM   		        	(31030)
#define WATCH_VAR_HOME             			(31040)
#define WATCH_VAR_ARRIVE           			(31050)
#define WATCH_VAR_BANK_GPI					(31060)

#define WATCH_VAR_GPO						(32000)
#define WATCH_VAR_ENABLE					(32010)
#define WATCH_VAR_CLEAR 					(32020)

#define WATCH_VAR_AI     					(33000)

#define WATCH_VAR_AO     					(34000)

#define WATCH_VAR_TRIGGER_EXECUTE			(38000)
#define WATCH_VAR_TRIGGER_STATUS			(38001)
#define WATCH_VAR_TRIGGER_POSITION			(38002)

#define WATCH_VAR_TRIGGER_COUNT				(38010)

#define WATCH_VAR_TRIGGER_NOTIFY_ENABLE			(38020)
#define WATCH_VAR_TRIGGER_NOTIFY_STATUS_ECHO	(38021)
#define WATCH_VAR_TRIGGER_NOTIFY_CLEAR_WAIT		(38022)

#define WATCH_VAR_TRIGGER_DELTA_CROSS_COUNT		(38110)


#define WATCH_VAR_POS_LOOP_ERROR			(40000)
#define WATCH_VAR_POS_LOOP_REF_POS			(40001)
#define WATCH_VAR_POS_LOOP_FILTER_VALUE		(40002)

#define WATCH_VAR_FIR_POS_IN				(48000)
#define WATCH_VAR_FIR_POS_OUT				(48001)

#define WATCH_VAR_WATCH_ENABLE				(52000)
#define WATCH_VAR_WATCH_TIME				(52001)
#define WATCH_VAR_WATCH_EVENT_VALUE_WORK	(52002)

#define WATCH_VAR_INT32						(52020)
#define WATCH_VAR_INT64						(52021)
#define WATCH_VAR_FLOAT						(52022)
#define WATCH_VAR_DOUBLE					(52023)
#define WATCH_VAR_BOOL						(52024)


#define WATCH_VAR_TERMINAL_LIMIT_POSITIVE		(53000)
#define WATCH_VAR_TERMINAL_LIMIT_NEGATIVE		(53001)
#define WATCH_VAR_TERMINAL_ALARM				(53002)
#define WATCH_VAR_TERMINAL_HOME					(53003)
#define WATCH_VAR_TERMINAL_GPI					(53004)
#define WATCH_VAR_TERMINAL_ARRIVE				(53005)
#define WATCH_VAR_TERMINAL_MPG					(53009)

#define WATCH_VAR_TERMINAL_ENABLE				(53010)
#define WATCH_VAR_TERMINAL_CLEAR				(53011)
#define WATCH_VAR_TERMINAL_GPO					(53012)

#define WATCH_VAR_TERMINAL_DAC					(53020)

#define WATCH_VAR_TERMINAL_PULSE				(53022)
#define WATCH_VAR_TERMINAL_ENCODER				(53023)
#define WATCH_VAR_TERMINAL_ADC					(53024)

#define WATCH_VAR_TERMINAL_AU_ENCODER			(53026)

#define WATCH_VAR_TERMINAL_PRF_POS				(53030)

#define WATCH_VAR_TERMINAL_TRIGGER_POSITION	    (53040)
#define WATCH_VAR_TERMINAL_TRIGGER_STATUS	    (53041)

#define WATCH_VAR_TERMINAL_COMMAND				(53100)
#define WATCH_VAR_TERMINAL_STATUS				(53101)

#define WATCH_VAR_EVENT_HIT						(60000)
#define WATCH_VAR_TASK_START					(61000)
#define WATCH_VAR_TASK_WORK						(61001)


#define VAR_FORMAT_INT						(1)
#define VAR_FORMAT_FLOAT					(2)
#define VAR_FORMAT_DOUBLE					(3)

#define WATCH_LOAD_MODE_NONE				(0)
#define WATCH_LOAD_MODE_BOOT				(2)
#define WATCH_LOAD_MODE_RUN					(3)



#define VAR_CALCULATE_MAX					(32)

#define VAR_CALCULATE_NONE					(0)
#define VAR_CALCULATE_OR					(1)
#define VAR_CALCULATE_AND					(3)
#define VAR_CALCULATE_NOT					(5)

#define VAR_CALCULATE_ADD					(11)
#define VAR_CALCULATE_SUB					(12)
#define VAR_CALCULATE_MUL					(13)
#define VAR_CALCULATE_DIV					(14)

GT_API GTN_LoadReadHsConfig(short core,char *pFile);
GT_API GTN_ReadHsOn(short core,short enable,short mode,double interval);

typedef struct
{
	short mode;
	short pad0;
	long band;		//�������жϵ�λ����
	long time;		//�������жϵ�λʱ��
	long pad1[2];
}TAxisArrivePrm;
GT_API GTN_GetStsEx(short core,short axis,long *pSts,short count=1,unsigned long *pClock=NULL);
GT_API GTN_SetAxisArriveMode(short core,short axis,TAxisArrivePrm *pPrm);
GT_API GTN_GetAxisArriveMode(short core,short axis,TAxisArrivePrm *pPrm);

typedef struct
{
	short runEmpty;
	long segUseCount;
	long segReceiveCount;
	short pad1[2];
	long pad2[2];
	double pad3[2];
}TCrdStatusEx;

GT_API GT_CrdStatusEx(short crd,TCrdStatusEx *pCrdStatus,short fifo);
GT_API GTN_CrdStatusEx(short core,short crd,TCrdStatusEx *pCrdStatus,short fifo);

GT_API GTN_SetCrdMPGMode(short core,short crd,short enable,short master,long masterEven,long slaveEven,short filterTime,short mode);
GT_API GTN_GetCrdMPGMode(short core,short crd,short *pEnable,short *pMaster,long *pMasterEven,long *pSlaveEven,short *pFilterTime,short *pMode,short *pFifoEnd);

typedef struct
{
	double pos;
	double vel;
	double velEnd;
	double acc;
	double dec;
	short  direction;
	short overrideSelect;
	short reserve[2];
} TMoveContinuousAbsolutePrm;

GT_API GTN_MoveContinuousAbsolute(short core,short profile,TMoveContinuousAbsolutePrm *pPrm,TListInfo *pListInfo=NULL,short group=0);

GT_API GTN_SetReadHs(short core,short enable,short mode,short interval);
GT_API GTN_ReadHsReadBuffer(short core,short *pData,long count);

typedef struct
{
	short mode;	    //�˶�����,0-��λ��6-PVT������������ʱ��֧��
	short enable;   //�Ƿ�ʹ�ܣ�0-��ʹ�ܣ�1-ʹ��
	short trigger;	//trigger������ȡֵ��1��ʼ
	short pad1;		//����
	long distance;	//����ʱƫ�����������ɸ�����λ������
	long posLimit;  //���¹滮�󣬴���λ��+ƫ�������ܳ�����ֵ
	double vel;     //Ŀ���ٶȣ����¹滮��Ŀ���ٶȣ���λ������/ms
	double acc;     //��Ҫ����ʱ�ļ��ٶȣ���λ������/ms
	double dec;		//�˶�������ƫ�����ļ��ٶȣ���λ������/ms
	double percent;	//���ٶ�S������ʱ��ٷֱȣ�����60��ʾ60%
	double reserve[4];
}TTriggerProfilePrm;

typedef struct
{
	short mode;
	short enable;
	short execute;			//�Ƿ�ִ����,0-δִ�У�1-ִ��
	short status;			//ִ�й����е�״̬������Ϊ0���쳣�򷵻ش�����
	long endPos;			//�յ�λ�ã�����+ƫ������
	long reserve[7];
}TTriggerProfileStatus;

GT_API GTN_SetTriggerProfilePrm(short core,short profile,TTriggerProfilePrm *pPrm);
GT_API GTN_GetTriggerProfileStatus(short core,short profile,TTriggerProfileStatus *pSts);

#define MC_LIMIT_POSITIVE               (0)
#define MC_LIMIT_NEGATIVE               (1)
#define LIMIT_MODE_EXTERMAL     				(0)
#define LIMIT_MODE_SOFT         				(1)
#define LIMIT_MODE_ALL          				(-1)

GT_API GTN_LmtsOnEx(short core,short axis,short limitType,short limitMode);
GT_API GTN_LmtsOffEx(short core,short axis,short limitType,short limitMode);

GT_API GTN_PrintLogInfo(short core,const char *pFileName,long start,long count);
GT_API GTN_PrintMcStsInfo(short core,const char *pFileName,short type,short index,short count);
GT_API GTN_PrintCommandInfo(short core,const char *pFileName,long start,long count);

/*-----------------------------------------------------------*/
/* ILC                                                       */
/*-----------------------------------------------------------*/
struct TIlcResult
{
	double ErrorMax;
	double ErrorAvg;
	double ErrorRms;
	double pad1[9];
	short  pad2[10];
};

GT_API GTN_InitIlc(short core);
GT_API GTN_StartIlc(short core,short crd);
GT_API GTN_StopIlc(short core,short crd,TIlcResult *pPrm);
GT_API GTN_SaveIlcFile(short core,char *pIlcFile);
GT_API GTN_LoadIlcFile(short core,short crd,char *filePath);

/*-----------------------------------------------------------*/
/* MovePos                                                   */
/*-----------------------------------------------------------*/
typedef struct
{
	short value;
}TMovePosPercent;

typedef struct
{
	short value;
}TMovePosSmoothTime;

typedef union
{
	TMovePosPercent percent;
	TMovePosSmoothTime smoothTime;
	double value[2];
}TMovePosUnion;

typedef struct
{
	double pos;
	double vel;
	double acc;
	double dec;
	short direction;
	short overrideSelect;
	short pad;
	short mode;
	TMovePosUnion data;
}TMovePosParameter;

typedef struct
{
	double pos[2];
	double vel[2];
	double acc;
	double dec;
	short direction;
	short overrideSelect;
	short pad;
	short mode;
	TMovePosUnion data;
}TMovePosTwoSegmentParameter;

typedef struct
{
	short profile;
	short pad1[3];
	double pos;
	double vel;
	double acc;
	double dec;
	short direction;
	short overrideSelect;
	short pad2;
	short mode;
	TMovePosUnion data;
}TMultiMovePosParameter;

typedef struct
{
	short profile;
	short pad1[3];
	double pos[2];
	double vel[2];
	double acc;
	double dec;
	short direction;
	short overrideSelect;
	short pad2;
	short mode;
	TMovePosUnion data;
}TMultiMovePosTwoSegmentParameter;
GT_API GTN_MovePos(short core,short profile,TMovePosParameter *pMovePos,TListInfo *pListInfo=NULL,short group=0);
GT_API GTN_MovePosTwoSegment(short core,short profile,TMovePosTwoSegmentParameter *pMovePos,TListInfo *pListInfo=NULL,short group=0);


/*----------------*/
/*�񾵼������ָ��*/
/*----------------*/
#define    SCAN_LASER_MODE_DUTY_RATIO          (0)
#define    SCAN_LASER_MODE_FREQUENCY           (1)
#define    SCAN_LASER_MODE_ANALOG              (2)
#define    SCAN_LASER_MODE_PARALLEL            (4)
#define    SCAN_LASER_MODE_NONE               (10)

/*ռ�ձ�ģʽ�̶�����*/
typedef struct
{
	double minDutyRatio;
	double maxDutyRatio;
	double frequency;
}TLaserDutyRatioModeParameterPro;
/*Ƶ��ģʽ�̶�����*/
typedef struct
{
	double minFrequency;
	double maxFrequency;
	double pulseWidth;
}TLaserFrequencyModeParameterPro;
/*ģ����ģʽ�̶�����*/
typedef struct
{
	double minVoltage;
	double maxVoltage;
}TlaserAnalogModeParameterPro;
/*����ʽ�̶�����*/
typedef struct
{
	double minParallel;                                    // ���ڼ���ģʽ�µĲ��ڼ�����С����ֵ
	double maxParallel;                                    // ���ڼ���ģʽ�µĲ��ڼ����������ֵ
}TlasetParallelModeParameterPro;
/*�������ģʽ�̶�����*/
typedef union
{
	TLaserDutyRatioModeParameterPro dutyRatioModePrm;
	TLaserFrequencyModeParameterPro frequencyModePrm;
	TlaserAnalogModeParameterPro analogModePrm;
	TlasetParallelModeParameterPro parallelModePrm;
	double data[8];
}TLaserParameterUnionPro;
/*������Ϣ����*/
typedef struct
{
	unsigned short laserOn;   //���⿪��״̬
	unsigned short laserMode; //PWM���ģʽ���궨��
	short pad[2];             //����
	double power;             //��������
	TLaserParameterUnionPro laserPrm;
}TLaserInfoPro;

typedef struct
{
	unsigned short laserMode; //PWM���ģʽ�������
	short pad[3];             //����
	TLaserParameterUnionPro laserPrm;
}TLaserParameterPro;

GT_API GTN_GetScanLaserLinkPro(short core,short scanCrd,short *pLaserChannel);
GT_API GTN_SetScanLaserLinkPro(short core,short scanCrd,short laserChannel,TListInfo *pListInfo=NULL);//�񾵼����,laserChannelΪ0���ǽ��
GT_API GTN_GetScanLaserInfoPro(short core,short scanCrd,TLaserInfoPro *pPrm);
GT_API GTN_SetScanLaserEnablePro(short core,short scanCrd,short laserEnable,TListInfo *pListInfo=NULL);//���⿪�ع�
GT_API GTN_SetScanLaserPrmPro(short core,short scanCrd,TLaserParameterPro *pLaserPrm,TListInfo *pListInfo=NULL);//����ģʽ�͹̶���������
GT_API GTN_SetScanLaserPowerPro(short core,short scanCrd,double power,TListInfo *pListInfo=NULL);//������������
GT_API GTN_SetScanLaserDelayPro(short core,short scanCrd,double laserOnDelay,double laserOffDelay,TListInfo *pListInfo);

/*----------------*/
/*�����ָ��    */
/*----------------*/
#define    SCAN_MOTION_MODE_NONE                (0)
#define    SCAN_MOTION_MODE_JUMP                (1)
#define    SCAN_MOTION_MODE_JUMP_POINT          (2)
#define    SCAN_MOTION_MODE_JUMP_TIME           (3)
#define    SCAN_MOTION_MODE_JUMP_TIME_POINT     (4)
#define    SCAN_MOTION_MODE_MARK                (5)
#define    SCAN_MOTION_MODE_MARK_TIME           (6)

#define    SCAN_MOTION_CIRCLE_DIR_CW            (0)
#define    SCAN_MOTION_CIRCLE_DIR_CCW           (1)
/*��ǰհ����*/
typedef struct
{
	short lookAheadNum;   //ǰհ����
	short highSpeedMode;
	short pad[2];         //����
	double time;          //ʱ�䳣��
	double radiusRatio;   //�������Ƶ��ڲ���
	double reserve[2];    //����
}TScanLookAheadParameterPro;

/*��״̬*/
typedef struct
{
	short run;                    //���˶���־
	short space;
	unsigned short fifoEmpty;     //�ܿձ�־
	short pad1;                   //����
	unsigned long segmentNumber;  //ִ�жκ�
	unsigned long commandReceive; //���յ���ָ����
	unsigned long commandSend;    //�ѷ��͵�ָ����
	long pad2;                    //����
	double prfVel;                //�ϳɹ滮�ٶ�
}TScanStatusPro;

//Jump�˶���Mark�˶�
typedef struct
{
	double acc;
	double dec;
	double vel;
}TVelModePro;

typedef struct
{
	double acc;
	double dec;
	unsigned long time;
	long pad;//����
}TTimeModePro;

typedef struct
{
	double acc;
	double dec;
	double vel;
	unsigned long motionDelayTime;
	unsigned long laserDelayTime;
}TVelPointModePro;

typedef struct
{
	double acc;
	double dec;
	unsigned long time;
	unsigned long motionDelayTime;
	unsigned long laserDelayTime;
	long pad;//����
}TTimePointModePro;

typedef union
{
	TVelModePro velMode;
	TTimeModePro timeMode;
	TVelPointModePro velPointMode;
	TTimePointModePro timePointMode;
	double data[8];
}TScanMotionPrmUnionPro;

typedef struct
{
	double pos[3];
	double reserve;
	TScanMotionPrmUnionPro motionPrm;
}TScanLinearMotionPro;

typedef struct
{
	double endPos[3];
	double radius;//�뾶���������Ż��ӻ�
	short dir;
	short pad[3];//����
	TScanMotionPrmUnionPro motionPrm;
}TScanCircularMotionPro;

typedef struct
{
	short multiMarkDelayMode;
	unsigned short jumpDelayLengthLimit;
	short pad[2];//����
	double multiMarkLaserOffDelay;
	double multiMarkDelayConst;
	double markDelay;
	double minJumpDelay;
	double maxJumpDelay;
}TScanDelayParameterPro;

GT_API GTN_ScanInitPro(short core,short scanCrd,TScanLookAheadParameterPro *pPrm,TListInfo *pListInfo);
GT_API GTN_GetScanCrdPosPro(short core,short scanCrd,double *pPos);
GT_API GTN_GetScanStatusPro(short core,short scanCrd,TScanStatusPro *pPrm);
GT_API GTN_ScanLinearPro(short core,short scanCrd,short motionMode,TScanLinearMotionPro *pPrm,TListInfo *pListInfo);
GT_API GTN_ScanCircularPro(short core,short scanCrd,short motionMode,TScanCircularMotionPro *pPrm,TListInfo *pListInfo);
GT_API GTN_SetScanDelayPrmPro(short core,short scanCrd,TScanDelayParameterPro *pPrm,TListInfo *pListInfo=NULL);
GT_API GTN_SetScanMotionDelayPro(short core,short scanCrd,double delayTime,TListInfo *pListInfo);
GT_API GTN_GetScanExecuteTimePro(short core,short scanCrd,double *pExecuteTime);
GT_API GTN_ClearScanExecuteTimePro(short core,short scanCrd);

#define LASER_ENABLE_DO	             (76)    //������ʹ���ź�
#define LASER_RED_LED_DO             (77)    //���������ָʾ�ź�
#define LASER_POWER_LATCH_DO         (78)    //���������������ź�
GT_API GTN_SetScanLaserIOPro(short core,short scanCrd,short doType,long doValue,TListInfo *pListInfo=NULL);

//20200713ͬ��GTS�ı������ƣ����������߼��
GT_API GT_SetEncResponseCheck(short control,short dacThreshold,double minEncVel,long time);
GT_API GT_GetEncResponseCheck(short control,short *pDacThreshold,double *pMinEncVel,long *pTime);
GT_API GT_EnableEncResponseCheck(short control);
GT_API GT_DisableEncResponseCheck(short control);

GT_API GTN_SetEncResponseCheck(short core,short control,short dacThreshold,double minEncVel,long time);
GT_API GTN_GetEncResponseCheck(short core,short control,short *pDacThreshold,double *pMinEncVel,long *pTime);
GT_API GTN_EnableEncResponseCheck(short core,short control);
GT_API GTN_DisableEncResponseCheck(short core,short control);

/************************************************************************/
/* ��ת�Ṧ��                                                           */
/************************************************************************/
#define ROTARY_DIRECTION_SELECT_MODE_DEFAULT                  (0)
#define ROTARY_DIRECTION_SELECT_MODE_SMART                    (1)

typedef struct
{
	short rotary;
	short pad[3];
	double start;
	double length;
	double reserve;
	double pulse;
} TRotaryConfig;

typedef struct
{
	short fifo;
	short overrideNum;
	short g0Mode;
	short reserve1[5];
	long segNum;
	long reserve2[3];
	double vel;
	double acc;
	double velEnd;
	double velLimit;
	double reserve3[8];
} TLineAbsolutePrm;

GT_API GTN_GetAxisPrfPosRotary(short core,short axis,double *pTheta,double *pRound,short count=1);
GT_API GTN_GetProfileRotaryConfig(short core,short profile,TRotaryConfig *pConfig);
GT_API GTN_GetPrfPosRotary(short core,short profile,double *pTheta,double *pRound,short count=1);
GT_API GTN_SetCrdScale(short core,short crd,short dimension,double alpha,double beta);
GT_API GTN_GetCrdScale(short core,short crd,short dimension,double *pAlpha,double *pBeta);
GT_API GTN_GetCrdRotaryConfig(short core,short crd,short dimension,TRotaryConfig *pConfig);
GT_API GTN_GetCrdPosRotary(short core,short crd,short dimension,double *pTheta,double *pRound,short count=1);
GT_API GTN_GetEncoderRotaryConfig(short core,short encoder,TRotaryConfig *pConfig);
GT_API GTN_GetEncPosRotary(short core,short encoder,double *pTheta,double *pRound,short count=1);
GT_API GTN_SetAxisRotaryConfig(short core,short axis,TRotaryConfig *pConfig);
GT_API GTN_GetAxisRotaryConfig(short core,short axis,TRotaryConfig *pConfig);
GT_API GTN_ZeroAxisRotaryRound(short core,short axis,short count=1);
GT_API GTN_LineAbsoluteEx(short core,short crd,double *pPos,short *pDir,TLineAbsolutePrm *pPrm);
GT_API GTN_SetAxisRotaryDirectionSelectMode(short core,short axis,short mode);
GT_API GTN_GetAxisRotaryDirectionSelectMode(short core,short axis,short *pMode);

typedef struct
{
	double pos;
	double vel;
	double acc;
	double velMax;
	double reserve1[4];
	short smoothTime;
	short enableRatio;
	short modal;
	short fifo;
	short dir;
	short reserve2[3];
	long segNum;
	long reserve3[3];
}TBufMoveAbsPrm;
GT_API GTN_BufMoveAbsoluteEx(short core,short crd,short moveAxis,TBufMoveAbsPrm *pPrm);


typedef struct
{
	short laserFollowMode;
	double maxFrq;
	double minFrq;
	double maxDuty;
	double minDuty;
	short pad1[7];
	double pad2[8];
}TLaserFollowPrm;

GT_API GTN_SetLaserFollowMode(short core,TLaserFollowPrm *pPrm,short channel);
GT_API GT_LaserFollowOff(short crd,short fifo,short channel);
GT_API GTN_LaserFollowOff(short core,short crd,short fifo,short channel);
GT_API GTN_SetLaserFollowTable(short core,short tableId,long n,double *pVel,double *pPower,short channel);

/*-----------------------------------------------------------*/
//ԭconfig.h�����ù��ܣ�����������ģ��                       */
/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* conifg of controller                                      */
/*-----------------------------------------------------------*/
#define RES_LIMIT                       (8)
#define RES_ALARM                       (8)
#define RES_HOME                        (8)
#define RES_GPI                         (16)
#define RES_ARRIVE                      (8)
#define RES_MPG                         (7)
#define RES_ENABLE                      (8)
#define RES_CLEAR                       (8)
#define RES_GPO                         (16)
#define RES_DAC                         (12)
#define RES_STEP                        (8)
#define RES_PULSE                       (8)
#define RES_ENCODER                     (11)
#define RES_LASER                       (2)
#define AXIS_MAX                        (8)
#define PROFILE_MAX                     (8)
#define CONTROL_MAX                     (8)
#define PRF_MAP_MAX                     (2)
#define ENC_MAP_MAX                     (2)

typedef struct DiConfig
{
	short active;
	short reverse;
	short filterTime;
} TDiConfig;

typedef struct CountConfig
{
	short active;
	short reverse;
	short filterType;

	short captureSource;
	short captureHomeSense;
	short captureIndexSense;
} TCountConfig;

typedef struct DoConfig
{
	short active;
	short axis;
	short axisItem;
	short reverse;
} TDoConfig;

typedef struct StepConfig
{
	short active;
	short axis;
	short mode;
	short parameter;
	short reverse;
} TStepConfig;

typedef struct DacConfig
{
	short active;
	short control;
	short reverse;
	short bias;
	short limit;
} TDacConfig;

typedef struct AdcConfig
{
	short active;
	short reverse;
	double a;
	double b;
	short filterMode;
} TAdcConfig;

typedef struct ControlConfig
{
	short active;
	short axis;
	short encoder1;
	short encoder2;
	long  errorLimit;
	short filterType[3];
	short encoderSmooth;
	short controlSmooth;
} TControlConfig;

typedef struct ControlConfigEx
{
	short refType;
	short refIndex;

	short feedbackType;
	short feedbackIndex;

	long  errorLimit;
	short feedbackSmooth;
	short controlSmooth;
} TControlConfigEx;

typedef struct ProfileConfig
{
	short  active;
	double decSmoothStop;
	double decAbruptStop;
} TProfileConfig;

typedef struct AxisConfig
{
	short active;
	short alarmType;
	short alarmIndex;
	short limitPositiveType;
	short limitPositiveIndex;
	short limitNegativeType;
	short limitNegativeIndex;
	short smoothStopType;
	short smoothStopIndex;
	short abruptStopType;
	short abruptStopIndex;
	long  prfMap;
	long  encMap;
	short prfMapAlpha[PRF_MAP_MAX];
	short prfMapBeta[PRF_MAP_MAX];
	short encMapAlpha[ENC_MAP_MAX];
	short encMapBeta[ENC_MAP_MAX];
} TAxisConfig;

typedef struct McConfig
{
	TProfileConfig profile[PROFILE_MAX];
	TAxisConfig    axis[AXIS_MAX];
	TControlConfig control[CONTROL_MAX];
	TDacConfig     dac[RES_DAC];
	TStepConfig    step[RES_STEP];
	TCountConfig   encoder[RES_ENCODER];
	TCountConfig   pulse[RES_PULSE];
	TDoConfig      enable[RES_ENABLE];
	TDoConfig      clear[RES_CLEAR];
	TDoConfig      gpo[RES_GPO];
	TDiConfig      limitPositive[RES_LIMIT];
	TDiConfig      limitNegative[RES_LIMIT];
	TDiConfig      alarm[RES_ALARM];
	TDiConfig      home[RES_HOME];
	TDiConfig      gpi[RES_GPI];
	TDiConfig      arrive[RES_ARRIVE];
	TDiConfig      mpg[RES_MPG];
} TMcConfig;

GT_API GT_SaveConfig(char *pFile);
GT_API GT_SetDiConfig(short diType,short diIndex,TDiConfig *pDi);
GT_API GT_GetDiConfig(short diType,short diIndex,TDiConfig *pDi);
GT_API GT_SetDoConfig(short doType,short doIndex,TDoConfig *pDo);
GT_API GT_GetDoConfig(short doType,short doIndex,TDoConfig *pDo);
GT_API GT_SetStepConfig(short step,TStepConfig *pStep);
GT_API GT_GetStepConfig(short step,TStepConfig *pStep);
GT_API GT_SetDacConfig(short dac,TDacConfig *pDac);
GT_API GT_GetDacConfig(short dac,TDacConfig *pDac);
GT_API GT_SetAdcConfig(short adc,TAdcConfig *pAdc);
GT_API GT_GetAdcConfig(short adc,TAdcConfig *pAdc);
GT_API GT_SetCountConfig(short countType,short countIndex,TCountConfig *pCount);
GT_API GT_GetCountConfig(short countType,short countIndex,TCountConfig *pCount);
GT_API GT_SetControlConfig(short control,TControlConfig *pControl);
GT_API GT_GetControlConfig(short control,TControlConfig *pControl);
GT_API GT_SetControlConfigEx(short control,TControlConfigEx *pControl);
GT_API GT_GetControlConfigEx(short control,TControlConfigEx *pControl);
GT_API GT_SetProfileConfig(short profile,TProfileConfig *pProfile);
GT_API GT_GetProfileConfig(short profile,TProfileConfig *pProfile);
GT_API GT_SetAxisConfig(short axis,TAxisConfig *pAxis);
GT_API GT_GetAxisConfig(short axis,TAxisConfig *pAxis);
GT_API GT_ProfileScale(short axis,short alpha,short beta);
GT_API GT_EncScale(short axis,short alpha,short beta);

GT_API GT_EncSns(unsigned short sense);
GT_API GT_LmtSns(unsigned short sense);
GT_API GT_GpiSns(unsigned short sense);
GT_API GT_SetAdcFilter(short adc,short filterTime);


GT_API GT_GetConfigTable(short type,short *pCount);
GT_API GT_GetConfigTableAll();

GT_API GT_SetMcConfig(TMcConfig *pMc);
GT_API GT_GetMcConfig(TMcConfig *pMc);

GT_API GT_SetMcConfigToFile(TMcConfig *pMc,char *pFile);
GT_API GT_GetMcConfigFromFile(TMcConfig *pMc,char *pFile);

GT_API GTN_SaveConfig(short core,char *pFile);
GT_API GTN_SetDiConfig(short core,short diType,short diIndex,TDiConfig *pDi);
GT_API GTN_GetDiConfig(short core,short diType,short diIndex,TDiConfig *pDi);
GT_API GTN_SetDoConfig(short core,short doType,short doIndex,TDoConfig *pDo);
GT_API GTN_GetDoConfig(short core,short doType,short doIndex,TDoConfig *pDo);
GT_API GTN_SetStepConfig(short core,short step,TStepConfig *pStep);
GT_API GTN_GetStepConfig(short core,short step,TStepConfig *pStep);
GT_API GTN_SetDacConfig(short core,short dac,TDacConfig *pDac);
GT_API GTN_GetDacConfig(short core,short dac,TDacConfig *pDac);
GT_API GTN_SetAdcConfig(short core,short adc,TAdcConfig *pAdc);
GT_API GTN_GetAdcConfig(short core,short adc,TAdcConfig *pAdc);
GT_API GTN_SetCountConfig(short core,short countType,short countIndex,TCountConfig *pCount);
GT_API GTN_GetCountConfig(short core,short countType,short countIndex,TCountConfig *pCount);
GT_API GTN_SetControlConfig(short core,short control,TControlConfig *pControl);
GT_API GTN_GetControlConfig(short core,short control,TControlConfig *pControl);
GT_API GTN_SetControlConfigEx(short core,short control,TControlConfigEx *pControl);
GT_API GTN_GetControlConfigEx(short core,short control,TControlConfigEx *pControl);
GT_API GTN_SetProfileConfig(short core,short profile,TProfileConfig *pProfile);
GT_API GTN_GetProfileConfig(short core,short profile,TProfileConfig *pProfile);
GT_API GTN_SetAxisConfig(short core,short axis,TAxisConfig *pAxis);
GT_API GTN_GetAxisConfig(short core,short axis,TAxisConfig *pAxis);
GT_API GTN_ProfileScale(short core,short axis,short alpha,short beta);
GT_API GTN_EncScale(short core,short axis,short alpha,short beta);

/*-----------------------------------------------------------*/
/* Config of Ext-Module                                      */
/*-----------------------------------------------------------*/
typedef struct
{
	short active;
	short checkError;
	short linkError;
	short packageErrorCount;
	short pad[8];
} TExtModuleStatus;

typedef struct
{
	short type;
	short input;
	short output;
} TExtModuleType;

typedef struct
{
	short station;
	short module;
	short index;
} TExtIoMap;

GT_API GT_OpenExtMdl(char *pDllName);
GT_API GT_CloseExtMdl();
GT_API GT_LoadExtConfig(char *pFileName);
GT_API GT_ResetExtMdl();
GT_API GTN_OpenExtMdl(short core,char *pDllName);
GT_API GTN_CloseExtMdl(short core);
GT_API GTN_ResetExtMdl(short core);
GT_API GTN_LoadExtConfig(short core,char *pFileName);
GT_API GTN_SetExtIoValue(short core,short module,unsigned short value);
GT_API GTN_GetExtIoValue(short core,short module,unsigned short *pValue);
GT_API GTN_LoadExtModuleConfig(short core,char *pFile);
GT_API GTN_SaveExtModuleConfig(short core,char *pFile);
GT_API GTN_ExtModuleOn(short core,short station);
GT_API GTN_ExtModuleOff(short core,short station);
GT_API GTN_GetExtModuleStatus(short core,short station,TExtModuleStatus *pStatus);
GT_API GTN_SetExtModuleId(short core,short station,short count,short *pId);
GT_API GTN_GetExtModuleId(short core,short station,short count,short *pId);
GT_API GTN_SetExtModuleReverse(short core,short station,short module,short inputCount,short *pInputReverse,short outputCount,short *pOutputReverse);
GT_API GTN_GetExtModuleReverse(short core,short station,short module,short inputCount,short *pInputReverse,short outputCount,short *pOutputReverse);
GT_API GTN_GetExtModuleCount(short core,short station,short *pCount);
GT_API GTN_GetExtModuleType(short core,short station,short module,TExtModuleType *pModuleType);
GT_API GTN_SetExtIoMap(short core,short type,short index,TExtIoMap *pMap);
GT_API GTN_GetExtIoMap(short core,short type,short index,TExtIoMap *pMap);
GT_API GTN_ClearExtIoMap(short core,short type);
GT_API GTN_SetExtAoRange(short core,short index,double max,double min);
GT_API GTN_GetExtAoRange(short core,short index,double *pMax,double *pMin);
GT_API GTN_SetExtAiRange(short core,short index,double max,double min);
GT_API GTN_GetExtAiRange(short core,short index,double *pMax,double *pMin);

/*-----------------------------------------------------------*/
/* Config of Laser and Scan                                  */
/*-----------------------------------------------------------*/
struct TScanCommandMotion
{
	long segmentNumber;
	short x;
	short y;
	long deltaX;
	long deltaY;
	long vel;
	long acc;
};

struct TScanCommandMotionDelay
{
	long delay;
};

struct TScanCommandDo
{
	short doType;
	short doMask;
	short doValue;
};

struct TScanCommandDoDelay
{
	long delay;
};

struct TScanCommandLaser
{
	short mask;
	short value;
} ;

struct TScanCommandLaserDelay
{
	long laserOnDelay;
	long laserOffDelay;
} ;

struct TScanCommandLaserPower
{
	long power;
} ;

struct TScanCommandLaserFrequency
{
	long frequency;
} ;

struct TScanCommandLaserPulseWidth
{
	long pulseWidth;
} ;

struct TScanCommandDa
{
	short daIndex;
	short daValue;
} ;

typedef struct
{
	short module;
	short fifo;
} TScanMap;

GT_API GTN_SetScanMap(short core,short scan,TScanMap *pMap);
GT_API GTN_GetScanMap(short core,short scan,TScanMap *pMap);
GT_API GTN_ClearScanMap(short core);
GT_API GTN_UpdateScanMap(short core);

/*-----------------------------------------------------------*/
/* Config of Position Compare                                */
/*-----------------------------------------------------------*/
typedef struct
{
	short module;
	short fifo;
} TPosCompareMap;

GT_API GTN_SetPosCompareMap(short core,short index,TPosCompareMap *pMap);
GT_API GTN_GetPosCompareMap(short core,short index,TPosCompareMap *pMap);
GT_API GTN_ClearPosCompareMap(short core);


/*-----------------------------------------------------------*/
//ԭringnet.h���͵Ȼ���������ع��ܵ�ָ��                    */
/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Ringnet                                                  */
/*-----------------------------------------------------------*/
#define RTN_SUCCESS				                        (0)
#define RTN_MALLOC_FAIL						            (-100) /* malloc memory fail */
#define RTN_FREE_FAIL							        (-101) /* free memory or delete the object fail */
#define RTN_NULL_POINT						            (-102) /* the param point input is null */
#define RTN_ERR_ORDER						            (-103) /* call the function order is wrong, some msg isn't validable */
#define RTN_PCI_NULL							        (-104) /* the pci address is empty, can't access the pci device*/
#define RTN_PARAM_OVERFLOW			                    (-105) /* the param input is too larget*/
#define RTN_LINK_FAIL							        (-106) /* the two ports both link fail*/
#define RTN_IMPOSSIBLE_ERR				                (-107) /* it means the system or same function work wrong*/
#define RTN_TOPOLOGY_CONFLICT			                (-108) /* the id conflict*/
#define RTN_TOPOLOGY_ABNORMAL		                    (-109) /* scan the net abnormal*/
#define RTN_STATION_ALONE				                (-110) /* the device no id, it means the device id is 0xF0 */
#define RTN_WAIT_OBJECT_OVERTIME	                    (-111) /* multi thread wait for object overtime */
#define RTN_ACCESS_OVERFLOW			                    (-112) /* data[i];  i is larger than the define */
#define RTN_NO_STATION						            (-113) /* the station accessed not existent */
#define RTN_OBJECT_UNCREATED			                (-114) /* the object not created yet*/
#define RTN_PARAM_ERR						            (-115) /* the param input is wrong*/
#define RTN_PDU_CFG_ERR                                 (-116) /*Pdu DMA Cfg Err*/
#define RTN_PCI_FPGA_ERR					            (-117) /*PCI op err or FPGA op err*/
#define RTN_CHECK_RW_ERR					            (-118) /*data write to reg, then rd out, and check err */
#define RTN_REMOTE_UNEABLE				                (-119) /*the device which will be ctrl by net can't be ctrl by net function*/

#define RTN_NET_REQ_DATA_NUM_ZERO		                (-120) /*mail op or pdu op req data num can't be 0*/
#define RTN_WAIT_NET_OBJECT_OVERTIME	                (-121) /* net op multi thread wait for object overtime */
#define RTN_WAIT_NET_RESP_OVERTIME		                (-122) /* Can't wait for resp */
#define RTN_WAIT_NET_RESP_ERR				            (-123) /*wait mailbox op err*/
#define RTN_INITIAL_ERR								    (-124) /*initial the device err*/
#define RTN_PC_NO_READY							        (-125) /*find the station'pc isn't work*/
#define RTN_STATION_NO_EXIST					        (-126)
#define RTN_MASTER_FUNCTION					            (-127) /* this funciton only used by master */

#define RTN_NOT_ALL_RETURN							    (-128) /* the GT_RN_PtProcessData funciton fail return */
#define RTN_NUM_NOT_EQUAL							    (-129) /* the station number of RingNet do not equal  the station number of CFG */

#define RTN_CHECK_STATION_ONLINE_NUM_ERR		        (-130) /*Check no slave*/
#define RTN_FILE_ERR_OPEN								(-131) /*open file error*/
#define RTN_FILE_ERR_FORMAT							    (-132) /*parse file error*/
#define RTN_FILE_ERR_MISSMATCH					        (-133) /*file info is not match with the actual ones*/
#define RTN_DMALIST_ERR_MISSMATCH			            (-134) /*can't find the slave*/

#define RTN_REQUSET_MAIL_BUS_OVERTIME		            (-150) /*Requset Mail Bus Err*/
#define RTN_INSTRCTION_ERR							    (-151) /*instrctions err*/
#define RTN_MAIL_RESP_REQ_ERR						    (-152) /*RN_MailRespReq  err*/
#define RTN_CTRL_SRC_ERR								(-153) /* the controlled source  is error */
#define RTN_PACKET_ERR									(-154) /*packet is error*/
#define RTN_STATION_ID_ERR							    (-155) /*the device id is not in the right rang*/
#define RTN_WAIT_NET_PDU_RESP_OVERTIME	                (-156) /*net pdu op wait overtime*/
#define RTN_ETHCAT_ENC_POS_ERR					        (-157) /**/

#define RTN_IDLINK_PACKET_ERR			            	(-200) /*ilink master  decode err! packet_length is not match*/
#define RTN_IDLINK_PACKET_END_ERR		                (-201) /* the ending of ilink packet is not 0xFF*/
#define RTN_IDLINK_TYPER_ERR					        (-202) /* the type of ilink module is error*/
#define RTN_IDLINK_LOST_CNT 					        (-203) /* the ilink module has lost connection*/
#define RTN_IDLINK_CTRL_SRC_ERR			                (-204) /* the controlled source of ilink module is error */
#define RTN_IDLINK_UPDATA_ERR				            (-205) /* the ilink module updata error*/
#define RTN_IDLINK_NUM_ERR					            (-206) /* the ilink num larger the IDLINK_MAX_NUM(30) */
#define RTN_IDLINK_NUM_ZERO					            (-207) /* the ilink num is zero */

#define RTN_NO_PACKET							        (301)  /* no valid packet */
#define RTN_RX_ERR_PDU_PACKET				            (-302) /* ERR PDU PACKET */
#define RTN_STATE_MECHINE_ERR				            (-303)
#define RTN_PCI_DSP_UN_FINISH				            (304)
#define RTN_SEND_ALL_FAIL						        (-305)
#define RTN_STATION_CLOSE					            (310)
#define RTN_STATION_RESP_FAIL				            (311)

#define RTN_UPDATA_MODAL_ERR			                (-330) /* update the modal in normal way fail*/

#define RTN_NO_MAIL_DATA						        (340) /*There is no mail data*/
#define RTN_NO_PDU_DATA						            (341) /*There is no pdu data*/

#define RTN_FILE_PARAM_NUM_ERR					        (-500)
#define RTN_FILE_PARAM_LEN_ERR					        (-501)
#define RTN_FILE_MALLOC_FAIL							(-502)
#define RTN_FILE_FREE_FAIL								(-503)
#define RTN_FILE_PARAM_ERR							    (-504)
#define RTN_FILE_NOT_EXSITS						    	(505)
#define RTN_FILE_CREATE_FAIL							(510)
#define RTN_FILE_DELETE_FAIL							(511)
#define RTN_FIFE_CRC_CHECK_ERR				        	(-512)
#define RTN_FIFE_FUNCTION_ID_RETURN_ERR	                (-600)
#define RTN_DLL_WINCE									(-800)
#define RTN_DLL_WIN32									(-801)
#define RTN_XML_STATION_ERR						        (-900)//dma config file confilit with slave type


GT_API GT_RN_GetEncPos(short encoder, double *pValue, short count, unsigned long *pClock);
GT_API GT_RN_GetAxisError(short axis, double *pValue, short count, unsigned long *pClock);
GT_API GT_RN_GetPrfMode(short axis, long* pValue, short count, unsigned long *pClock);
GT_API GT_RN_GetAuEncPos(short encoder, double *pValue, short count, unsigned long *pClock);
GT_API GT_RN_GetCaptureStatus(short encoder, short* pStatus, long *pValue, short count, unsigned long *pClock);
GT_API GT_RN_GetSts(short axis, long* pSts, short count, unsigned long *pClock);
GT_API GT_RN_GetPowerSts(long* pValue);
GT_API GT_RN_GetEcatAxisACTArray(short axis, short *pCur, short* pTorque, short count);
GT_API GT_RN_PtSpaceArray(short profile, short *pSpace, short fifo, short count);
GT_API GT_RN_GetDoEx(short doType, long* pValue);
GT_API GT_RN_GetDiEx(short diType, long* pValue);
GT_API GT_RN_GetDo(short doType, long* pValue);
GT_API GT_RN_GetDi(short diType, long* pValue);
GT_API GTN_LoadRingNetConfig(short core,char*pFile);
GT_API GTN_SaveRingNetConfig(short core,char *pFile);

#define TERMINAL_LOAD_MODE_NONE             (0)
#define TERMINAL_LOAD_MODE_BOOT             (2)

typedef struct
{
	unsigned short type;
	short id;
	long status;
	unsigned long synchCount;
	unsigned long ringNetType;
	unsigned long portStatus;
	unsigned long sportDropCount;
	unsigned long reserve[7];
} TTerminalStatus;

GT_API GTN_TerminalInit(short core,short detect=1);
GT_API GTN_GetTerminalVersion(short core,short index,TVersion *pTerminalVersion);
GT_API GTN_SetTerminalPermit(short core,short index,short dataType,unsigned short permit);
GT_API GTN_SetTerminalPermitEx(short core,short station,short dataType,short *permit,short index,short count);
GT_API GTN_GetTerminalPermitEx(short core,short station,short dataType,short *pPermit,short index,short count);

GT_API GTN_FindStation(short core,short station,unsigned long time);
GT_API GTN_GetTerminalPermit(short core,short index,short dataType,unsigned short *pPermit);
GT_API GTN_ProgramTerminalConfig(short core,short loadMode);
GT_API GTN_GetTerminalConfigLoadMode(short core,short *pLoadMode);

GT_API GTN_ReadPhysicalMap(void);
GT_API ConvertPhysical(short core,short dataType,short terminal,short index);

GT_API GTN_SetTerminalSafeMode(short core,short index,short safeMode);
GT_API GTN_GetTerminalSafeMode(short core,short index,short *pSafeMode);
GT_API GTN_ClearTerminalSafeMode(short core,short index);
GT_API GTN_GetTerminalStatus(short core,short index,TTerminalStatus *pTerminalStatus);
GT_API GTN_GetTerminalType(short core,short count,unsigned short *pType,short *pTypeConnect=NULL);

/*-----------------------------------------------------------*/
/* ��ȡSPORT������                                           */
/*-----------------------------------------------------------*/
#define SPORT_COUNT                     (256)

typedef struct
{
	unsigned long terminalTxBuf[SPORT_COUNT];
	unsigned long terminalRxBuf[SPORT_COUNT];
}TTerminalData;

GT_API GTN_ReadTerminalData(short core,TTerminalData *pTerminalData);

/*-----------------------------------------------------------*/
/* Config of module                                          */
/*-----------------------------------------------------------*/
#define TERMINAL_OPERATION_NONE             (0)
#define TERMINAL_OPERATION_SKIP             (1)
#define TERMINAL_OPERATION_CLEAR            (2)
#define TERMINAL_OPERATION_RESET_MODULE     (3)

#define TERMINAL_OPERATION_PROGRAM          (11)

typedef struct
{
	unsigned long portACrcOkCnt;
	unsigned short portACrcErrorCnt;
	unsigned long portBCrcOkCnt;
	unsigned short portBCrcErrorCnt;
	unsigned long reserve;//Ŀǰ���ڶ�ȡFLASH�����ݳ���
} TRingNetCrcStatus;

typedef struct
{
	unsigned short errorCountReceive;
	unsigned short errorCountPackageDown;
	unsigned short errorCountPackageUp;
	unsigned short reserve[13];
} TTerminalError;

typedef struct
{
	short moduleDataType;
	short moduleDataIndex;
	short dataIndex;
	short dataCount;
} TTerminalMap;

GT_API GT_SetMailbox(short core,short station,unsigned short byteAddress,unsigned short *pData,unsigned short wordCount,unsigned short dataMode,unsigned short desId,unsigned short type);
GT_API GT_GetMailbox(short core,short station,unsigned short byteAddress,unsigned short *pData,unsigned short wordCount,unsigned short dataMode,unsigned short desId,unsigned short type);

GT_API GTN_LoadTerminalConfig(short core,char *pFile);
GT_API GTN_SaveTerminalConfig(short core,char *pFile);
GT_API GTN_TerminalOn(short core,short index);
GT_API GTN_TerminalSynch(short core,short index);
GT_API GTN_GetRingNetCrcStatus(short core,short index,TRingNetCrcStatus *pRingNetCrcStatus);
GT_API GTN_GetTerminalError(short core,short index,TTerminalError *pTerminalError);
GT_API GTN_SetTerminalType(short core,short count,short *pType);
GT_API GTN_GetTerminalPhyId(short core,short count,short *pPhyId);
GT_API GTN_GetTerminalLinkStatus(short core,short count,short *ringNetType,short *pLinkStatus);
GT_API GTN_SetTerminalMap(short core,short dataType,short moduleIndex,TTerminalMap *pMap);
GT_API GTN_GetTerminalMap(short core,short dataType,short moduleIndex,TTerminalMap *pMap);
GT_API GTN_ClearTerminalMap(short core,short dataType);
GT_API GTN_SetTerminalMode(short core,short station,unsigned short mode);
GT_API GTN_GetTerminalMode(short core,short station,unsigned short *pMode);
GT_API GTN_SetTerminalTest(short core,short station,short index,unsigned short value);
GT_API GTN_GetTerminalTest(short core,short station,short index,unsigned short *pValue);
GT_API GTN_SetTerminalOperation(short core,short operation);
GT_API GTN_GetTerminalOperation(short core,short *pOperation);
GT_API GTN_SetMailbox(short core,short station,unsigned short byteAddress,unsigned short *pData,unsigned short wordCount,unsigned short dataMode,unsigned short desId,unsigned short type);
GT_API GTN_GetMailbox(short core,short station,unsigned short byteAddress,unsigned short *pData,unsigned short wordCount,unsigned short dataMode,unsigned short desId,unsigned short type);
GT_API GTN_GetUuid(short core,char *pCode,short count);

/*-----------------------------------------------------------*/
/* ��ȫģʽ����                                              */
/*-----------------------------------------------------------*/
GT_API GTN_RN_ClearStationSafeModeStatus(short cardIndex,short stationPhyId);
GT_API GTN_RN_IlinkSetSafeModeControl(short cardIndex,short stationPhyId,short modulePhyId,short enable,short clearMode);
GT_API GTN_RN_IlinkClearSafeModeStatus(short cardIndex,short stationPhyId,short modulePhyId);
GT_API GTN_RN_IlinkSetSafeModeOut(short cardIndex,short stationPhyId,short modulePhyId,short type,short index,short *pEnable,double *pValue,short count);

/*-----------------------------------------------------------*/
//ԭLookAheadEx.h����ǰհ��ع��ܵ�ָ��                      */
/*-----------------------------------------------------------*/
#define LA_AXIS_NUM    8
#define LA_WORK_AXIS_NUM  6

//��Ĳ�����Ϣ����������ٶȣ����������ٶȣ���������ٶȱ仯�����Ƿ������ٶ�ģʽ
#define AXIS_LIMIT_NONE       0       //��������
#define AXIS_LIMIT_MAX_VEL    1       //������ٶ�����
#define AXIS_LIMIT_MAX_ACC    2       //�������ٶ�����
#define AXIS_LIMIT_MAX_DV     4       //������ٶ�����������

#define KIN_MSG_BUFFER_SIZE   32

//�ٶȹ滮ģʽ
enum EVelMode
{
	T_CURVE=0,
	S_CURVE,
	S_CURVE_NEW,                  //���ݼӼ��ٶȡ������ٶȽ���S�����ٶ�ǰհ��2015.11.16
	S_CURVE_SMOOTH,

	VEL_MODE_MAX=0x10000,         //ȷ������Ϊ4Byte
};

//��������ϵ�¹켣�Ƿ������ٶ�ģʽ
enum EWorkLimitMode
{
	WORK_LIMIT_INVALID=0,       //��������ϵ��Ϣ������
	WORK_LIMIT_VALID,           //��������ϵ������Ч

	WORK_LIMIT_MODE_MAX=0x10000,//ȷ������Ϊ4Byte
};

//���õ��ٶȶ������
enum EVelSettingDef
{
	NORMAL_DEF_VEL=0,             //����Ϊ������ϵ������ĺϳ��ٶ�
	NUM_DEF_VEL,                  //��NUMϵͳ�Ĺ�����
	CUT_DEF_VEL,                  //�ٶ�Ϊ�����ٶ�

	VEL_SETTING_DEF_MAX=0x10000,  //ȷ������Ϊ4Byte
};

//���õļ��ٶȶ������
enum EAccSettingDef
{
	NORMAL_DEF_ACC=0,             //���뼴���
	LONG_AXIS_ACC,                //��������ٶ�

	ACC_SETTING_DEF_MAX=0x10000,  //ȷ������Ϊ4Byte
};

//��������
enum EMachineMode
{
	NORMAL_THREE_AXIS=0,      //��׼�������ģʽ
	MULTI_AXES,               //��������ģʽ
	FIVE_AXIS,                //�������ģʽ,������ϵΪ������������ϵΪ��
	FIVE_AXIS_WORK,           //�������ģʽ����������ϵΪ����������ϵΪ��
	ROBOT,                    //������ģʽ��������ϵΪ������������ϵΪ����2014.12.3
	ROBOT_WORK,

	MACHINE_MODE_MAX=0x10000, //ȷ������Ϊ4Byte
};

//ǰհ�����ṹ��
struct TLookAheadParameter
{
	int lookAheadNum;					//ǰհ����
	double time;						//ʱ�䳣��
	double radiusRatio;					//�������Ƶ��ڲ���
	double vMax[LA_AXIS_NUM];			//���������ٶ�
	double aMax[LA_AXIS_NUM];			//����������ٶ�
	double DVMax[LA_AXIS_NUM];			//���������ٶȱ仯������ʱ�䳣���ڣ�
	double scale[LA_AXIS_NUM];			//��������嵱��
	short axisRelation[LA_AXIS_NUM];	//����������ڲ�����Ķ�Ӧ��ϵ
	char machineCfgFileName[128];		//���������ļ���
};

//////////////////////////////////////
typedef struct
{
	short RobotType;
	short reserved1;

	short KinParUse[18];
	double KinPar[18];
	short KinLimitUse[12];
	double KinLimitMin[12];
	double KinLimitMax[12];
	double KinLimitMinShift[12];
	double KinLimitMaxShift[12];

	short AxisUse[8];
	char AxisPosSignSwitch[8];
	double AxisPosOffset[8];

	short CartUnitUse[6];
	char CartPosKCSSignSwitch[6];
	short reserved2[3];
	double CartPosKCSOffset[6];
}RC_KIN_CONFIG;

typedef struct
{
	char Error;
	short ErrorID;
	char Message[129];
}RC_ERROR_INTERFACE;

typedef struct
{
	short ErrorID;
	char Message[129];
	char LogTime[32];
	long InternalID;
}RC_MSG_BUFFER_ELEMENT;

typedef struct
{
	short LastMsgIndex;
	RC_MSG_BUFFER_ELEMENT MsgElement[KIN_MSG_BUFFER_SIZE];
	long LastMsgID;
}RC_MSG_BUFFER;

//����ⷽ��
enum ETransDir
{
	FORWARD_TRANS=0,            //����
	INVERSE_TRANS,              //���

	TRANS_DIR_MAX = 0x10000,	// ȷ������Ϊ4Byte
};

//��ת�᷶Χ����
struct TRotationAxisRange
{
	int primaryAxisRangeOn;              //��һ��ת���޶���Χ�Ƿ���Ч��0������Ч��1����Ч
	int slaveAxisRangeOn;                //�ڶ���ת���޶���Χ�Ƿ���Ч��0������Ч��1����Ч
	double maxPrimaryAngle;              //��һ��ת�����ֵ
	double minPrimaryAngle;              //��һ��ת����Сֵ
	double maxSlaveAngle;                //�ڶ���ת�����ֵ
	double minSlaveAgnle;                //�ڶ���ת����Сֵ
};

//ѡ�����
enum EGroupSelect
{
	Continuous=0,
	Group_1,
	Group_2,
};

enum OptimizeState
{
	OPT_OFF=0,
	OPT_ON,
};

enum OptimizeMethod
{
	NO_OPT=0,
	OPT_BLENDING,
	OPT_CIRCLEFITTING,
	OPT_CUBICSPLINE,
	OPT_BSPLINE,
};

enum ErrorID
{
	INIT_ERROR=1,		                    //û�н��в�����ʼ��
	PASSWORD_ERROR,		                    //����������ڹ̸��˶�����ƽ̨������
	INDATA_ERROR,		                    //�������ݴ��󣨼��Բ�������Ƿ���ȷ��
	PRE_PROCESS_ERROR,
	TOOL_RADIUS_COMPENSATE_ERROR_INOUT,		//���߰뾶�������󣺽���/����������������Բ��
	TOOL_RADIUS_COMPENSATE_ERROR_NOCROSS,	//���߰뾶�����������ݲ������޷����㽻��
	USERDATA_ERROR,
};

//�켣�Ż������ṹ��
typedef struct OptimizeParamUser
{
	OptimizeState usePathOptimize;	//�Ƿ�ʹ��·���Ż���OPT_OFF:��ʹ��	OPT_ON:ʹ��

	float tolerance;				//����(suggest: rough:0.1, pre-finish:0.05, finish:0.01)

	OptimizeMethod optimizeMethod;	//ѡ�������Ż���ʽ

	OptimizeState keepLargeArc;		//�Ƿ�����Բ����OPT_OFF���������� OPT_ON������

	float blendingMinError;			//blending����С�趨���

	float blendingMaxAngle;			//blending�����Ƕ����ƣ������߶������Ƕȴ��ڸýǶ�ʱ������blending����λ���ȣ�

}TOptimizeParamUser;

struct TErrorInfo
{
	ErrorID errorID;		//�����(INIT_ERROR:δ��ʼ��������PRE_PROCESS_ERROR:Ԥ����ģ�����
	//TOOL_RADIUS_COMPENSATE_ERROR:���߰뾶��������)
	long errorRowNum;		//�����к�
};

struct TPreStartPos
{
	double Pos[LA_AXIS_NUM];
};

enum EMachineType
{
	RW_C_ON_B=0,//B Ϊ��һ��ת�ᣬC Ϊ�ڶ���ת��
	RW_B_ON_A,	//A Ϊ��һ��ת�ᣬB Ϊ�ڶ���ת��
	RW_A_ON_B,	//B Ϊ��һ��ת�ᣬA Ϊ�ڶ���ת��
	RW_C_ON_A,	//A Ϊ��һ��ת�ᣬC Ϊ�ڶ���ת��
	DT_B_ON_A,	//A Ϊ��һ��ת�ᣬB Ϊ�ڶ���ת��
	DT_A_ON_B,	//B Ϊ��һ��ת�ᣬA Ϊ�ڶ���ת��
	DT_A_ON_C,	//C Ϊ��һ��ת�ᣬA Ϊ�ڶ���ת��
	DT_B_ON_C,	//C Ϊ��һ��ת�ᣬB Ϊ�ڶ���ת��
	T_A_W_B,	//A Ϊ��һ��ת�ᣬB Ϊ�ڶ���ת��
	T_B_W_A,	//B Ϊ��һ��ת�ᣬA Ϊ�ڶ���ת��
	T_A_W_C,	//A Ϊ��һ��ת�ᣬC Ϊ�ڶ���ת��
	T_B_W_C,	//B Ϊ��һ��ת�ᣬC Ϊ�ڶ���ת��
};
struct TMachCfgInfo
{
	EMachineType machineType;            //��������
	short reserve1[2];                   //��������
	double primaryAxisPoint[3];          //��һ��ת��������MCS������
	double slaveAxisPoint[3];            //�ڶ���ת��������MCS������
	double toolLocationPoint[3];         //��������ϵ������MCS������
	short dirMode;                       //��������ģʽ
	short reserve2[2];                   //��������
	short dir[5];                        //���᷽��
	double axisVector[5][3];             //�������߷���
};

typedef struct
{
	short frqTableId;
	short dutyTableId;
	double pad1[8];
	short pad2[8];
}TLaserFollowDuoTablePrm;

GT_API GT_SetupLookAheadCrd(short crd,EMachineMode machineMode);
GT_API GT_SetVelDefineModeLa(short crd,EVelSettingDef velDefMode);
GT_API GT_SetAccDefineModeLa(short crd,EAccSettingDef accDefMode);
GT_API GT_SetAxisLimitModeLa(short crd,int *pAxisLimitMode);
GT_API GT_SetWorkLimitModeLa(short crd,EWorkLimitMode workLimitMode);
GT_API GT_SetAxisFollowModeLa(short crd,int *pFollowMode);
GT_API GT_SetAxisVelValidModeLa(short crd,int velValidAxis);
GT_API GT_SetArcAllowErrorLa(short crd, double error);
GT_API GT_SetMinEvenVelTimeLa(short crd, double evenTime);
GT_API GT_SetMinDccAngleLa(short crd, double dccAngle);
GT_API GT_SetProfilePeriod(short crd, double profilePeriod);
GT_API GT_SetFilterTime(short crd, long filtNum);
GT_API GT_SetPrecisionControl(short crd, short mode,double error);
GT_API GT_SetVelSmoothModeLa(short crd, short smoothMode);
GT_API GT_SetVelModeLa(short crd,EVelMode velMode);
GT_API GT_InitLookAheadEx(short crd,TLookAheadParameter *pLookAheadPara,short fifo,short motionMode=0,TPreStartPos *pPreStartPos=NULL);
GT_API GT_PrintLACmdLa(short crd,int printFlag, int clearFile);

GT_API GT_GetLookAheadSegCountEx(short crd,long *pSegCount,short fifo=0);
GT_API GT_GetMotionTimeEx(short crd,double *pTime,short fifo=0);
GT_API GT_SetUserSegNumEx(short crd,long segNum,short fifo=0);
GT_API GT_CrdDataEx(short crd,TCrdData *pCrdData,short fifo=0);

GT_API GT_LnXYEx(short crd,double x,double y,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_LnXYG0Ex(short crd,double x,double y,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_LnXYZEx(short crd,double x,double y,double z,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_LnXYZG0Ex(short crd,double x,double y,double z,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_LnXYZAEx(short crd,double x,double y,double z,double a,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_LnXYZAG0Ex(short crd,double x,double y,double z,double a,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_LnXYZACEx(short crd,double *pPos,short posMask,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_LnXYZACG0Ex(short crd,double *pPos,short posMask,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_LnXYZACUVWEx(short crd,double *pPos,short posMask,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_LnXYZACUVWG0Ex(short crd,double *pPos,short posMask,double synVel,double synAcc,long segNum,short override2,short fifo=0);

GT_API GT_ArcXYREx(short crd,double x,double y,double radius,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_ArcYZREx(short crd,double y,double z,double radius,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_ArcZXREx(short crd,double z,double x,double radius,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_ArcXYCEx(short crd,double x,double y,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_ArcYZCEx(short crd,double y,double z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_ArcZXCEx(short crd,double z,double x,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_ArcXYZEx(short crd,double x,double y,double z,double interX,double interY,double interZ,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_HelixXYRZEx(short crd,double x,double y,double z,double radius,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_HelixXYCZEx(short crd,double x,double y,double z,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_HelixYZRXEx(short crd,double x,double y,double z,double radius,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_HelixYZCXEx(short crd,double x,double y,double z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_HelixZXRYEx(short crd,double x,double y,double z,double radius,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_HelixZXCYEx(short crd,double x,double y,double z,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);

GT_API GT_HelixXYRMultiZEx(short crd,double *pPos,double radius,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_HelixXYCMultiZEx(short crd,double *pPos,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_HelixYZRMultiXEx(short crd,double *pPos,double radius,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_HelixYZCMultiXEx(short crd,double *pPos,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_HelixZXRMultiYEx(short crd,double *pPos,double radius,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GT_HelixZXCMultiYEx(short crd,double *pPos,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);

GT_API GT_BufDelayEx(short crd,unsigned short delayTime,short fifo=0);
GT_API GT_BufIOEx(short crd,unsigned short doType,unsigned short doMask,unsigned short doValue,short fifo=0);
GT_API GT_BufDAEx(short crd,short channel,short daValue,short fifo=0);
GT_API GT_BufEnableDoBitPulseEx(short crd,short doType,short doIndex,unsigned short highLevelTime,unsigned short lowLevelTime,long pulseNum,short firstLevel,short fifo);
GT_API GT_BufDisableDoBitPulseEx(short crd,short doType,short doIndex,short fifo);
GT_API GT_BufGearEx(short crd,short gearAxis,double deltaPos,short fifo=0);
GT_API GT_BufMoveEx(short crd,short moveAxis,double pos,double vel,double acc,short modal,short fifo=0);
GT_API GTN_BufMoveSpEx(short core,short crd,short moveAxis,double pos,double vel,short smoothTime,short modal,short enableRatio,short fifo);
GT_API GTN_BufMoveSpSetPrmEx(short core,short crd,short moveAxis,double acc,double dec,double velMax,short fifo);
GT_API GT_BufFollowMasterEx(short crd,TBufFollowMaster *pBufFollowMaster,short fifo=0);
GT_API GT_BufFollowEventCrossEx(short crd,TBufFollowEventCross *pEventCross,short fifo=0);
GT_API GT_BufFollowEventTriggerEx(short crd,TBufFollowEventTrigger *pEventTrigger,short fifo=0);
GT_API GT_BufFollowStartEx(short crd,long masterSegment,long slaveSegment,long masterFrameWidth,short fifo=0);
GT_API GT_BufFollowNextEx(short crd,long width,short fifo=0);
GT_API GT_BufFollowReturnEx(short crd,double vel,double acc,short smoothPercent,short fifo=0);

GT_API GT_BufSmartCutterOnEx(short crd,short index,short fifo);
GT_API GT_BufSmartCutterOffEx(short crd,short index,short fifo);

GT_API GT_BufLaserOnEx(short crd,short fifo=0,short channel=0);
GT_API GT_BufLaserOffEx(short crd,short fifo=0,short channel=0);
GT_API GT_BufLaserFollowModeEx(short crd,short source,short fifo,short channel,double startPower=0);
GT_API GT_BufLaserFollowTableEx(short crd,short tableId,double minPower,double maxPower,short fifo,short channel);
GT_API GT_BufLaserFollowOffEx(short crd,short fifo,short channel);
GT_API GT_BufLaserPrfCmdEx(short crd,double laserPower,short fifo=0,short channel=0);
GT_API GT_BufLaserFollowRatioEx(short crd,double ratio,double minPower,double maxPower,short fifo,short channel);
GT_API GTN_SetupLookAheadCrd(short core,short crd,EMachineMode machineMode);
GT_API GTN_SetAxisFollowModeLa(short core,short crd,int *pFollowMode);
GT_API GTN_SetMinEvenVelTimeLa(short core,short crd, double evenTime);
GT_API GTN_SetMinDccAngleLa(short core,short crd,double dccAngle);
GT_API GTN_SetVelDefineModeLa(short core,short crd,EVelSettingDef velDefMode);
GT_API GTN_SetAccDefineModeLa(short core,short crd,EAccSettingDef accDefMode);
GT_API GTN_SetMaxOverrideLa(short core,short crd,double maxSynVelRatio);
GT_API GTN_SetAxisLimitModeLa(short core,short crd,int *pAxisLimitMode);
GT_API GTN_SetWorkLimitModeLa(short core,short crd,EWorkLimitMode workLimitMode);
GT_API GTN_SetAxisVelValidModeLa(short core,short crd,int velValidAxis);
GT_API GTN_SetVelModeLa(short core,short crd,EVelMode velMode);
GT_API GTN_SetVelSmoothModeLa(short core,short crd,short smoothMode);
GT_API GTN_PrintLACmdLa(short core,short crd,int printFlag, int clearFile);
GT_API GTN_UpdateMachineBuildingFileLa(short core,short crd, int update);
GT_API GTN_InitialMachineBuilding(short core,short crd, char *pMachineCfgFileName,double *machineCoordCenter, double *workCoordCenter, double toolLength);
GT_API GTN_InitialMachineBuildingEx(short core,short crd, char *pMachineCfgFileName,double *machineCoordCenter, double *workCoordCenter, double toolLength);
GT_API GTN_InitialMachineBuildingPara(short core,short crd, TMachCfgInfo *pMachCfgInfo,double *machineCoordCenter, double *workCoordCenter, double toolLength);
GT_API GTN_CrdRTCPOn(short core,short crd,short fifo=0);
GT_API GTN_CrdRTCPOff(short core,short crd,short fifo=0);
GT_API GTN_SetNonlinearErrorControl(short core,short crd, int enable, double nonlinearError);
GT_API GTN_EnableDiscreateArc(short core,short crd,short enable,double arcError);
GT_API GTN_MachineForwardTrans(short core,short crd, double *pMachinePos, double *pWorkPos);
GT_API GTN_MachineRTCPTrans(short core,short crd, double *pInputPos, double *pMachinePos, double *pWorkPos);
GT_API GTN_SetAxisVelValidCompModeLa(short core,short crd, int enable, int *pCompAxis);
GT_API GTN_SetFollowAxisProcessModeLa(short core,short crd,int AxisFollowMode);
GT_API GTN_SetCmdVelLimitLa(short core,short crd, int enable, int n1, int n2, int mode);
GT_API GTN_InitLookAheadEx(short core,short crd,TLookAheadParameter *pLookAheadParameter,short fifo, short motionMode=0,TPreStartPos *pPreStartPos=NULL);
GT_API GTN_InitLookAheadPara(short core,short crd,long lookAheadNum,double time,double radiusRatio,double scale,short fifo);
GT_API GTN_SetFollowAxisParaLa(short core,short crd,int *pAxisLimitMode,double *pVmax,double *pAmax,double *pDVmax);
typedef struct
{
	short type;
	short index[2];
} TAddition;
GT_API GTN_SetAxisAddition(short core,short axis,short dataType,TAddition *pAddition);
GT_API GTN_GetAxisAddition(short core,short axis,short dataType,TAddition *pAddition);

GT_API GTN_SetCompToolLength(short core,short crd, double compToolLength);
GT_API GTN_SetCompWorkCoordOffset(short core,short crd, double *pCompWorkOffset);

GT_API GTN_GetLookAheadSegCountEx(short core,short crd,long *pSegCount,short fifo=0);
GT_API GTN_GetMotionTimeEx(short core,short crd,double *pTime,short fifo);
GT_API GTN_SetUserSegNumEx(short core,short crd,long segNum,short fifo);
GT_API GTN_CrdDataEx(short core,short crd,TCrdData *pCrdData,short fifo=0);

GT_API GTN_LnXYEx(short core,short crd,double x,double y,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GTN_LnXYG0Ex(short core,short crd,double x,double y,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GTN_LnXYZEx(short core,short crd,double x,double y,double z,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GTN_LnXYZG0Ex(short core,short crd,double x,double y,double z,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GTN_LnXYZAEx(short core,short crd,double x,double y,double z,double a,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GTN_LnXYZAG0Ex(short core,short crd,double x,double y,double z,double a,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GTN_LnXYZACEx(short core,short crd,double *pPos,short posMask,double synVel,double synAcc,long segNum,short override2,short fifo);
GT_API GTN_LnXYZACG0Ex(short core,short crd,double *pPos,short posMask,double synVel,double synAcc,long segNum,short override2,short fifo);
GT_API GTN_LnXYZACUVWEx(short core,short crd,double *pPos,short posMask,double synVel,double synAcc,long segNum,short override2,short fifo);
GT_API GTN_LnXYZACUVWG0Ex(short core,short crd,double *pPos,short posMask,double synVel,double synAcc,long segNum,short override2,short fifo);
GT_API GTN_ArcXYREx(short core,short crd,double x,double y,double radius,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GTN_ArcYZREx(short core,short crd,double y,double z,double radius,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GTN_ArcZXREx(short core,short crd,double z,double x,double radius,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GTN_ArcXYCEx(short core,short crd,double x,double y,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GTN_ArcYZCEx(short core,short crd,double y,double z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GTN_ArcZXCEx(short core,short crd,double z,double x,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GTN_ArcXYZEx(short core,short crd,double x,double y,double z,double interX,double interY,double interZ,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GTN_ArcXYRACEx(short core,short crd,double x,double y,double a,double c,double radius,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GTN_ArcXYCACEx(short core,short crd,double x,double y,double a,double c,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GTN_ArcXYZACEx(short core,short crd,double x,double y,double z,double a,double c,double interX,double interY,double interZ,double interA,double interC,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GTN_HelixXYRZEx(short core,short crd,double x,double y,double z,double radius,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GTN_HelixXYCZEx(short core,short crd,double x,double y,double z,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,long segNum,short override2,short fifo=0);
GT_API GTN_BufDelayEx(short core,short crd,unsigned short delayTime,short fifo=0);
GT_API GTN_BufGearEx(short core,short crd,short gearAxis,double deltaPos,short fifo=0);
GT_API GTN_BufMoveEx(short core,short crd,short moveAxis,double pos,double vel,double acc,short modal,short fifo=0);
GT_API GTN_BufIOEx(short core,short crd,unsigned short doType,unsigned short doMask,unsigned short doValue,short fifo=0);
GT_API GTN_BufEnableDoBitPulseEx(short core,short crd,short doType,short doIndex,unsigned short highLevelTime,unsigned short lowLevelTime,long pulseNum,short firstLevel,short fifo);
GT_API GTN_BufDisableDoBitPulseEx(short core,short crd,short doType,short doIndex,short fifo);
GT_API GTN_BufDAEx(short core,short crd,short chn,short daValue,short fifo=0);

GT_API GTN_BufFollowMasterEx(short core,short crd,TBufFollowMaster *pBufFollowMaster,short fifo=0);
GT_API GTN_BufFollowEventCrossEx(short core,short crd,TBufFollowEventCross *pEventCross,short fifo=0);
GT_API GTN_BufFollowEventTriggerEx(short core,short crd,TBufFollowEventTrigger *pEventTrigger,short fifo=0);
GT_API GTN_BufFollowStartEx(short core,short crd,long masterSegment,long slaveSegment,long masterFrameWidth,short fifo=0);
GT_API GTN_BufFollowNextEx(short core,short crd,long width,short fifo=0);
GT_API GTN_BufFollowReturnEx(short core,short crd,double vel,double acc,short smoothPercent,short fifo=0);

GT_API GTN_BufSmartCutterOnEx(short core,short crd,short index,short fifo=0);
GT_API GTN_BufSmartCutterOffEx(short core,short crd,short index,short fifo=0);

GT_API GTN_BufLaserOnEx(short core,short crd,short fifo=0,short channel=0);
GT_API GTN_BufLaserOffEx(short core,short crd,short fifo=0,short channel=0);
GT_API GTN_BufLaserFollowModeEx(short core,short crd,short source,short fifo,short channel,double startPower=0);
GT_API GTN_BufLaserFollowTableEx(short core,short crd,short tableId,double minPower,double maxPower,short fifo,short channel);
GT_API GTN_BufLaserFollowOffEx(short core,short crd,short fifo,short channel);
GT_API GTN_BufLaserPrfCmdEx(short core,short crd,double laserPower,short fifo=0,short channel=0);
GT_API GTN_BufSetPulseWidthEx(short core,short crd,unsigned short width,short fifo=0,short channel=0);
GT_API GTN_BufLaserFollowRatioEx(short core,short crd,double ratio,double minPower,double maxPower,short fifo,short channel);

GT_API GT_BufWaitDiEx(short crd, short diType, unsigned short diIndex,unsigned short level, short continueTime, long overTime, short flagMode,long segNum, short fifo);
GT_API GT_BufWaitLongVarEx(short crd,short index,long value,long overTime,short flagMode,long segNum,short fifo);
GT_API GTN_BufWaitDiEx(short core,short crd, short diType, unsigned short diIndex,unsigned short level, short continueTime, long overTime, short flagMode,long segNum, short fifo);
GT_API GTN_BufWaitLongVarEx(short core,short crd, short index,long value,long overTime,short flagMode,long segNum,short fifo);

GT_API GT_BufDoBitEx(short crd,unsigned short doType,unsigned short index,short value,short fifo);
GT_API GTN_BufDoBitEx(short core,short crd,unsigned short doType,unsigned short index,short value,short fifo);
GT_API GTN_BufDoBitDelayEx(short core,short crd,unsigned short doType,unsigned short index,short value,long delayTime,short fifo);


GT_API GTN_BufPosCompareStart(short core,short crd,short fifo,short index);
GT_API GTN_BufPosCompareStop(short core,short crd,short fifo,short index);

GT_API GT_BufPosCompareStartEx(short core,short crd,short fifo,short index);
GT_API GT_BufPosCompareStopEx(short core,short crd,short fifo,short index);
GT_API GTN_BufPosComparePsoPrm(short core,short crd,short index,TPosComparePsoPrm *pPrm,short fifo);
GT_API GTN_BufPosComparePsoPrmEx(short core,short crd,short index,TPosComparePsoPrm *pPrm,short fifo);
GT_API GTN_BufPosCompareStartEx(short core,short crd,short fifo,short index);
GT_API GTN_BufPosCompareStopEx(short core,short crd,short fifo,short index);
GT_API GTN_BufPosComparePulse(short core,short crd,short index,short outputMode,short level,unsigned short outputPulseWidth,short fifo);
GT_API GTN_BufPosComparePulseEx(short core,short crd,short index,short outputMode,short level,unsigned short outputPulseWidth,short fifo);
GT_API GTN_BufPosCompareMultiPulse(short core,short crd,short index,TPosCompareMultiPulse *pPosComparePulse,short fifo);
GT_API GTN_BufPosCompareMultiPulseEx(short core,short crd,short index,TPosCompareMultiPulse *pPosComparePulse,short fifo);

GT_API GTN_BufMoveJogEx(short core,short crd,short moveAxis,double vel,double acc,short modal,short fifo);
GT_API GTN_BufStopEx(short core,short crd,long mask,long option,short fifo);

GT_API GTN_BufLaserFollowDuoTableEx(short core,short crd,TLaserFollowDuoTablePrm *pPrm,short fifo,short channel);
GT_API GTN_SetRadiusRatioTableLa(short core,short crd,short count,double *pRadius,double *pRatio);

/*-----------------------------------------------------------*/
/* Comp                                                      */
/*-----------------------------------------------------------*/

GT_API GTN_BufPrfCompEnableEx(short core,short crd,short fifo,short profile,short enable,short enableType = 0);

typedef struct
{
	double kp;
	double ki;
	double kd;
	double integralLimit;	//���ּ���
	double derivativeLimit;	//΢�ּ���
	double limit;			//�������ƣ������ѹ��
	double pad1[4];
}TAxisPressPid;

#define PRESS_COMPENSATE_MODE_LINEAR                       (0)                           // ���Բ���
#define PRESS_COMPENSATE_MODE_TABLE	                       (1)                           // �����
#define PRESS_COMPENSATE_MODE_REGION_LEARN                 (2)                           // ��������ѧϰ����

typedef struct
{
	short enable;		           //�Ƿ�ʹ�ܣ�0-�رգ�1-ʹ��
	short type;			           //�������ͣ���ѹ������ģ������
	short dimension;	           //���������ά�ȣ����3ά
	short index[3];		           //���������,DAC��1��ʼ��ECAT IOģ��վ�Ŵ�0��ʼ
	short subIndex[3];             //�������������,DAC�ò�����Ч��ECAT IOģ���IOMAP��0��ʼ
	short mode;			           //ģʽ�����Ի��ǲ��
	short revolveAxis;             //����������ת�Ƕȵ����
	short regionAxisIndex;         //��������������Ч�Ĳο���
	short relatedMasterIndex;      //�涯���������
	short pad1[3];
	double target;			       //Ŀ�������ѹ
	double thredshold;		       //thredshold��ʲôʱ��ʼ����
	double deadZone;		       //���������ѹ�������ڲ�����
	double factor;			       //����λ�Ƶ�ת��ϵ��
	double revolveOffset;	       //��ʼ��ת����������Ĭ�Ϻϳɷ����ingdex[0]�ķ����غ�
	double revolveScale;	       //��ת���һȦ������
	TAxisPressPid pid;
	long compPosMaxP;              //�������λ������[N,P]�Ķ˵�P
	long compPosMaxN;              //�������λ������[N,P]�Ķ˵�N
	double k;	                   //�������˲�ϵ�� 0-1 ��ֵԽ���˲�Խǿ
	double pad2[4];
	long activeRegionP;            //����������Ч�Ĺ滮λ������[N,P]�Ķ˵�P
	long activeRegionN;            //����������Ч�Ĺ滮λ������[N,P]�Ķ˵�N
	long activeRegionInterval;     //����������Ч�Ĺ滮λ�������ڵ���ѧϰ�������modeΪ��ѧϰPRESS_COMPENSATE_MODE_REGION_LEARNʱ��Ч
	long relatedMasterEven;        //�涯����ı���
	long relatedSlaveEven;         //�涯����ı���
	long pad3[3];
} TAxisPressCompensate;

GT_API GT_SetAxisPressCompensate(short axis,TAxisPressCompensate *pPressComp);
GT_API GT_GetAxisPressCompensate(short axis,TAxisPressCompensate *pPressComp);
GT_API GTN_SetAxisPressCompensate(short core,short axis,TAxisPressCompensate *pPressComp);
GT_API GTN_GetAxisPressCompensate(short core,short axis,TAxisPressCompensate *pPressComp);
GT_API GT_SetAxisPressCompensateTable(short axis,short index,long count,double *pPressData,double *pPosData);
GT_API GT_SelectAxisPressCompensateTable(short axis,short index);
GT_API GTN_SetAxisPressCompensateTable(short core,short axis,short index,long count,double *pPressData,double *pPosData);
GT_API GTN_SelectAxisPressCompensateTable(short core,short axis,short index);

typedef struct
{
	short type;			      //�������ͣ���ѹ������ģ������
	short dimension;	      //���������ά�ȣ����3ά
	short index[3];		      //���������,DAC��1��ʼ��ECAT IOģ��վ�Ŵ�0��ʼ
	short subIndex[3];        //�������������,DAC�ò�����Ч��ECAT IOģ���IOMAP��0��ʼ

	double targetMax;	      //�궨�������ֵ���ﵽ�򳬹���ֵʱ�궨����
	double targetMin;	      //�궨������Сֵ���ﵽ��С�ڸ�ֵʱ�궨����
	double factor;		      //����λ�Ƶ�ת��ϵ��������ʱ����0,��ȡ״̬ʱ�õ��궨ֵ��

	long fixRegionP;          //�궨�滮λ������[N,P]�Ķ˵�P������λ�õ����λ��
	long fixRegionN;          //�궨�滮λ������[N,P]�Ķ˵�N������λ�õ����λ��
	long fixRegionInterval;   //�궨�滮λ�������ڵı궨���

	long tmp[16];
} TAxisPressCompensateFixFactor;

GT_API GTN_StartAxisPressCompensateFixFactor(short core,short axis,TAxisPressCompensateFixFactor *pPressComp);
GT_API GTN_GetAxisPressCompensateFixFactorStatus(short core,short axis,short *pFixFactorSts,TAxisPressCompensateFixFactor *pPressComp);

typedef struct
{
	short type;			 //�������ͣ���ѹ������ģ������
	short dimension;     //���������ά�ȣ����3ά
	short index[3];		 //���������,DAC��1��ʼ��ECAT IOģ��վ�Ŵ�0��ʼ
	short subIndex[3];   //�������������,DAC�ò�����Ч��ECAT IOģ���IOMAP��0��ʼ

	double target;		 //Ŀ�������ѹ
	double factor;		 //����λ�Ƶ�ת��ϵ��
	TAxisPressPid pid;

	long fixPosLimitP;   //�궨λ������[N,P]�Ķ˵�P
	long fixPosLimitN;   //�궨����λ������[N,P]�Ķ˵�N
	double thredshold;   //thredshold��ʲôʱ��ʼ����
	double deadZone;	 //���������ѹ�������ڲ�����

	//�������ڲ�����������ʹ�ã������û��ӿ�û�иò���
	double Knp;			 //ѹ����ȫ������
	double K1;			 //ȫ���������ϵ��1
	double K2;			 //ȫ���������ϵ��2
	double K3;			 //ȫ���������ϵ��3
	double Krise;		 //����ϵ��
	double Kpeak;		 //��ֵϵ��
	double Tset;		 //Ŀ����Ӧʱ��
	double Td;			 //������Ӧʱ��

	double tmp[8];
} TAxisPressCompensateFixPid;

GT_API GTN_StartAxisPressCompensateFixPid(short core,short axis,TAxisPressCompensateFixPid *pPressComp);
GT_API GTN_GetAxisPressCompensateFixPidStatus(short core,short axis,short *pFixPidSts,TAxisPressCompensateFixPid *pPressComp);

GT_API GTN_AxisPressCompensateEnable(short core,short axis,short enable,double deadZone,double factor,TListInfo *pListInfo);
GT_API GTN_SetAxisPressCompensateTarget(short core,short axis,double target,double thredshold,TListInfo *pListInfo);

GT_API GTN_BufAxisPressCompensatePrmEx(short core,short crd,short axis,double target,double thredshold,short fifo=0);
GT_API GTN_BufAxisPressCompensateEx(short core,short crd,short axis,short enable,double deadZone,double factor,short fifo=0);

GT_API GTN_SetAdcBias(short core,short adc,short bias);
GT_API GTN_GetAdcBias(short core,short adc,short *pBias);
GT_API GTN_SetAuAdcBias(short core,short auAdc,short bias);
GT_API GTN_GetAuAdcBias(short core,short auAdc,short *pBias);

GT_API GTN_SetCrdUserDataEndVelLa(short core,short crd, short crdUserDataType,double endVel);

/*-----------------------------------------------------------*/
/* PVTģʽ�������������                                      */
/*-----------------------------------------------------------*/
#define PVT_OPERATION_TYPE_LASER_ON					(2)
#define PVT_OPERATION_TYPE_BUF_DA					(4)
#define PVT_OPERATION_TYPE_LASER_CMD				(5)
#define PVT_OPERATION_TYPE_LASER_FOLLOW_RATIO		(6)
#define PVT_OPERATION_TYPE_LASER_FOLLOW_MODE		(25)
#define PVT_OPERATION_TYPE_LASER_FOLLOW_OFF			(26)
#define PVT_OPERATION_TYPE_BUF_DO_BIT				(94)
#define CRD_OPERATION_TYPE_BUF_POS_COMPARE_START 	(90)
#define CRD_OPERATION_TYPE_BUF_POS_COMPARE_STOP 	(91)

typedef struct
{
	short doType;
	short index;
	short value;
}TPVTDoBit;

typedef struct
{
	short chn;
	short daValue;
}TPVTDA;

typedef struct
{
	short chn;
	short enable;
}TPVTLaserSwitch;

typedef struct
{
	short chn;
	double power;
}TPVTLaserPrfCmd;

typedef struct
{
	short  chn;
	double ratio;
	double minPower;
	double maxPower;
}TPVTLaserFollowRatio;

typedef struct
{
	short  chn;
}TPVTLaserFollowOff;

typedef struct
{
	short  chn;
	short  source;
	double startPower;
}TPVTLaserFollowMode;

typedef struct
{
	short  index;
}TPVTPosCompareStart;

typedef struct
{
	short  index;
}TPVTPosCompareStop;

typedef struct
{
	unsigned short torqueMax;
	unsigned short torquePostive;
	unsigned short torqueNegitive;
	short reserve1;
	double reserve2[4];
}TTorqueLimit;

GT_API GTN_RN_SetTorqueLimit(short core,short axis,TTorqueLimit *pTorqueLimit);
GT_API GTN_RN_GetTorqueLimit(short core,short axis, TTorqueLimit *pTorqueLimit);
GT_API GTN_RN_GetAbsEncPosEx(short core,short encoder, long long *pEncPos);
GT_API GTN_RN_SetEncMultiLinesEx(short core, short encoder,unsigned long long multiLines);


GT_API GTN_RN_SetServoPidRatio(short core,short axis,double ratio);
GT_API GTN_RN_GetServoPidRatio(short core,short axis,double *pRatio);

#define SERBVO_POS_LOOP                   (0)		// ������λ�û�
#define SERBVO_SPD_LOOP                   (1)       // �������ٶȻ�
GT_API GTN_RN_GetServoPid(short core,short axis,short loop,short mode,void *pServoPid);
GT_API GTN_RN_SetServoPid(short core,short axis,short loop,short mode,void *pServoPid);

typedef struct
{
	short optimizeMode;
	short blendingType;
	short pad[2];
	double tolerance;
	double blendingPrm;
	double blendingMinAngle;
	double blendingMaxAngle;
} TPathOptimizePrm;
GT_API GTN_SetPathOptimizePrmLa(short core,short crd,short enable,short mode,void *pPrm);   //�켣�Ż�

/*---------------------------------------------------------------------------------------------*/
/* ����ͨѶָ�ͨ��485/232ͨ��ָ���gts.lib�е������Ƽ�ʹ�ã�							   */
/*---------------------------------------------------------------------------------------------*/
GT_API GTN_RN_ComSerialOpen(short cardIndex, short stationPhyId, short comIndex);
GT_API GTN_RN_ComSerialClose(short cardIndex, short stationPhyId, short comIndex);
GT_API GTN_RN_ComSerialRead(short cardIndex, short stationPhyId, short comIndex, unsigned long  readLen, unsigned long *pResLen, unsigned char *pData);
GT_API GTN_RN_ComSerialReadFast(short cardIndex, short stationPhyId, short comIndex, unsigned long readLen, unsigned long *pResLen, unsigned char *pData);
GT_API GTN_RN_ComSerialWrite(short cardIndex, short stationPhyId, short comIndex,unsigned long writeLen, unsigned long *pResLen, unsigned char *pData);
GT_API GTN_RN_ComSerialGetState(short cardIndex, short stationPhyId, short comIndex, unsigned char *pState);
GT_API GTN_RN_ComSerialSetSettings(short cardIndex, short stationPhyId, short comIndex, unsigned long baudrate, unsigned char stopBits, unsigned char parity);
GT_API GTN_RN_ComSerialClearErr(short cardIndex, short stationPhyId, short comIndex, unsigned char flag);
GT_API GTN_RN_ComSerialSetMode(short cardIndex, short stationPhyId, short comIndex, unsigned short comMode);
GT_API GTN_RN_ComSerialGetRecvFifoCnt(short cardIndex, short stationPhyId, short comIndex,short *pCount);

//��չģ������Ѱַָ�
GT_API GTN_RN_SetExtDiDoReversePhysical(short cardIndex, short stationPhyId, short moduleId, long* pInputReverse, long inputCount,long *pOutputReverse,long outputCount);
GT_API GTN_RN_GetExtDiDoReversePhysical(short cardIndex, short stationPhyId, short moduleId, long* pInputReverse, long inputCount,long *pOutputReverse,long outputCount);
GT_API GTN_RN_GetExtAoPhysical(short cardIndex, short stationPhyId, short moduleId, long aoIndex,double* pValue, long count);
GT_API GTN_RN_GetExtAoValuePhysical(short cardIndex, short stationPhyId, short moduleId, long aoIndex,long* pValue, long count);
GT_API GTN_RN_GetExtAiPhysical(short cardIndex, short stationPhyId, short moduleId, long aiIndex,double* pValue, long count);
GT_API GTN_RN_GetExtAiValuePhysical(short cardIndex, short stationPhyId, short moduleId, long aiIndex,long* pValue, long count);
GT_API GTN_RN_SetExtAoValuePhysical(short cardIndex, short stationPhyId, short moduleId, long aoIndex,long* pValue, long count);
GT_API GTN_RN_SetExtAoPhysical(short cardIndex, short stationPhyId, short moduleId, long aoIndex,double* pValue, long count);
GT_API GTN_RN_GetExtDiBitPhysical(short cardIndex, short stationPhyId, short moduleId, long diIndex, unsigned long* pValue, long count);
GT_API GTN_RN_GetExtDiPhysical(short cardIndex, short stationPhyId, short moduleId, unsigned long* pValue, long count);
GT_API GTN_RN_GetExtDoPhysical(short cardIndex, short stationPhyId, short moduleId,unsigned  long* pValue, long count);
GT_API GTN_RN_SetExtDoBitPhysical(short cardIndex,short stationPhyId,short moduleId,long doIndex,unsigned long* pValue,long count);
GT_API GTN_RN_SetExtDoPhysical(short cardIndex, short stationPhyId, short moduleId, unsigned long* pValue, long count);
GT_API GTN_RN_SetExtModuleMode(short cardIndex,short mode);
GT_API GTN_RN_GetExtModuleMode(short cardIndex,short *pMode);
GT_API GTN_RN_UpdateExtModuleFirmware(short cardIndex, short stationPhyId, short moduleId, const char* pFile);
GT_API GTN_RN_SetExtModuleComLedSts(short cardIndex, short stationPhyId, short moduleId, long value);
GT_API GTN_RN_GetExtModuleInfo(short cardIndex, short stationPhyId, short moduleId, short infoType, long *pValue);

GT_API GTN_BufPosComparePsoPrmPro(short core,short crd,short index,TPosComparePsoPrmPro *pPrmPro,short fifo);
GT_API GTN_BufPosComparePsoPrmProEx(short core,short crd,short index,TPosComparePsoPrmPro *pPrmPro,short fifo);




























/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
/*                        �����汾���ܺ���		                          */
/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
GT_API GT_GetCardType(unsigned long *pCardTypeArray,short cardTypeArraySize,short *pCardTypeCount);
GT_API GTN_GetCardType(unsigned long *pCardTypeArray,short cardTypeArraySize,short *pCardTypeCount);

GT_API GTN_SetAxisCircularSafetyZone(short core,short safetyZoneIndex,short enable,TAxisCircularSafetyZone *pPrm);
GT_API GTN_GetAxisCircularSafetyZone(short core,short safetyZoneIndex,short *pEnable,TAxisCircularSafetyZone *pPrm);
GT_API GTN_SetPrfRefSafetyZone(short core,short profile,short enable,TProfileReferenceSafetyZone *pPrm);
GT_API GTN_GetPrfRefSafetyZone(short core,short profile,short *pEnable,TProfileReferenceSafetyZone *pPrm);
GT_API GTN_GetPrfRefSafetyZoneSts(short core,short profile,long *pSts);

GT_API GTN_GetFunIdPro(short core,char *pFunName,short *pFunId);
GT_API GTN_GetVarIdPro(short core,char *pFunName,char *pVarName,TVarInfo *pVarInfo);

GT_API GTN_SetVarValueEx(short core,short page,TVarInfo *pVarInfo,double *pValue,short count=1);
GT_API GTN_GetVarValueEx(short core,short page,TVarInfo *pVarInfo,double *pValue,short count=1);

GT_API GTN_BufMultiLaserFollowOn(short core,short crd,long laserChannelMask,short fifo);
GT_API GTN_BufMultiLaserFollowOff(short core,short crd,long laserChannelMask,short fifo);
GT_API GTN_BufMultiLaserOn(short core,short crd,long laserChannelMask,short fifo);
GT_API GTN_BufMultiLaserOff(short core,short crd,long laserChannelMask,short fifo);

GT_API GTN_SetCrdContourErrorControlPrm(short core,short crd,short crdAxis,short enable,double *pCoef,short coefCount);
GT_API GTN_GetCrdContourErrorControlPrm(short core,short crd,short crdAxis,short *pEnable,double *pCoef,short *pCoefCount);

GT_API GTN_InitFPGAEncoder(short core);
GT_API GTN_SetFPGAEncoder(short core,short enable,long intervalTime,short reverseMask);
GT_API GTN_GetFPGAEncoder(short core,long *pDataChn1,long *pDataChn2,long *pDataChn3,long *pDataChn4,long *pCount,short *pOverFlowFlag);

typedef struct
{
	short followMode;     //λ�ñȽ���������ģʽ,0���������
	short hsoOutputMode;  //hso���ģʽ��0���������1������λ�ñȽ�ָ�����ò��������2�����ո���ָ������ֵ�����
	short timeScale;      //ʱ�侫�ȣ�0��1us��1��0.1us
	short pad;
	double maxValue;
	double minValue;
	double k;
	double b;
}TPosCompareFollowCrd;
GT_API GTN_SetCrdPosCompareFollowPulseWidthPrm(short core,short crd,short posCompareIndex,short hsoIndex,TPosCompareFollowCrd *pPosCompareFollowCrd,short count);
GT_API GTN_CrdPosCompareFollowPulseWidthEnable(short core,short crd,short posCompareIndex,short enable);

GT_API GTN_SetGantryModePro(short core,short group,short master,short slave,short mode,long syncErrorLimit);

typedef struct
{
	unsigned long objectIndex;   //һ��ָ����
	unsigned short subIndex;     //����ָ����
	unsigned short reserve;      //����λ
	short byteSize;              //�ֽڳߴ�
	short memType;               //����洢λ�� 0-RAM  1-FLASH
}TServoParamReader;
GT_API GTN_ReadServoParamInfo(short core,short axis, TServoParamReader *pTServoParamReader, unsigned char* pData);
GT_API GTN_WriteServoParamInfo(short core,short axis, TServoParamReader *pTServoParamReader, unsigned char* pData);
GT_API GTN_RN_GetServoAlarmInfo(short core,short axis,unsigned long *pAlarmCode);

GT_API GTN_WriteServo35thHomingFlag(short core, short axis, short flag);

GT_API GTN_BufSetLongVar(short core,short crd,short index,long value,short fifo);
GT_API GTN_BufSetDoubleVar(short core,short crd,short index,double value,short fifo);

GT_API GTN_SetAxisPrediction(short core,short axis,short mode,short enable,double *pCoef,short count1,short count2);
GT_API GTN_GetAxisPrediction(short core,short axis,short *pMode,short *pEnable,double *pCoef,short *pCount1,short *pCount2);

GT_API GTN_InitializeCommandListConfig(short core,TCommandListConfig *pConfig,short count=2);

GT_API GTN_LaserFollowMode(short core,short laserChannel,short *pLaserFollowSource,double *pLaserFollowStartPower,short laserCount);
GT_API GTN_LaserFollowRatio(short core,short laserChannel,double *pLaserFollowRatio,double *pLaserFollowMinPower,double *pLaserFollowMaxPower,short laserCount);

/*-----------------------------------------------------------*/
/* ����ָ�ָ��                                              */
/*-----------------------------------------------------------*/
GT_API GTN_RN_Recover(short cardIndex);

/*-----------------------------------------------------------*/
/* GSHD�����С��������                                      */
/*-----------------------------------------------------------*/
GT_API GTN_SetTorqueLimit(short core,short axis,TTorqueLimit *pTorqueLimit);
GT_API GTN_GetTorqueLimit(short core,short axis, TTorqueLimit *pTorqueLimit);

/*-----------------------------------------------------------*/
/* GSHD�ջ���������                                          */
/*-----------------------------------------------------------*/
typedef struct
{
	double value;
	double reverse[4];
}TServoPosLoopPidMode0;

typedef union
{
	TServoPosLoopPidMode0 servoPosLoopPidMode0;
}TServoPosLoopPidUnion;

typedef struct
{
	short mode;
	TServoPosLoopPidUnion servoPosLoopPidPrm;
}TServoPosLoopPid;

GT_API GTN_SetServoPosLoopPid(short core,short axis,TServoPosLoopPid *pServoPosLoopPid);
GT_API GTN_GetServoPosLoopPid(short core,short axis,TServoPosLoopPid *pServoPosLoopPid);

/*-----------------------------------------------------------*/
/* ��ȫģʽ����                                              */
/*-----------------------------------------------------------*/
GT_API GTN_RN_SetStationSafeModeControl(short cardIndex,short stationPhyId,short enable,short clearMode);
GT_API GTN_RN_SetStationSafeModeOut(short cardIndex,short stationPhyId,short type,short index,short *pEnable,double *pValue,short count);

GT_API GT_SetMaxOverrideLa(short crd,double maxSynVelRatio);

GT_API GTN_SetVelLookAheadModeLa(short core,short crd,int velMode);     //���ٶ�ǰհģʽģʽ

#define SLAVE_MIDDLE_POS_DIMENSION_MAX		3
typedef struct
{
	double targetPos;						// ����Ŀ��λ��
	double safetyPos;						// ��ȫ����λ��
	double slaveMiddlePos[SLAVE_MIDDLE_POS_DIMENSION_MAX];				// �����м��λ����Ϣ
} TBufLeapFrogInfo;
GT_API GTN_BufLeapFrogEx(short core,short crd,short axis,TBufLeapFrogInfo *pLeapFrogInfo,short modal,short fifo=0);

GT_API GTN_BufMultiLaserFollowOnEx(short core,short crd,long laserChannelMask,short fifo);
GT_API GTN_BufMultiLaserFollowOffEx(short core,short crd,long laserChannelMask,short fifo);
GT_API GTN_BufMultiLaserOnEx(short core,short crd,long laserChannelMask,short fifo);
GT_API GTN_BufMultiLaserOffEx(short core,short crd,long laserChannelMask,short fifo);

GT_API GTN_BufSetLongVarEx(short core,short crd,short index,long value,short fifo);
GT_API GTN_BufSetDoubleVarEx(short core,short crd,short index,double value,short fifo);

/*-----------------------------------------------------------*/
/* ����ֵ�������������                                      */
/*-----------------------------------------------------------*/
GT_API GTN_SetAuAbsEncMultiTurnRange(short core,short encoder,double range);
GT_API GTN_ReadAuAbsEncPos(short core,short encoder,double *pPos);

GT_API GTN_PvtTableUserData(short core,short tableId,short userDataType,double time,void *pData);

GT_API GTN_GetTrapRunTime(short core,short profile,TTrapPrm *pPrm,double currentPos,double targetPos,double targetVel,double runPos,double *pRunTime);
GT_API GTN_GetTrapRunPos(short core,short profile,TTrapPrm *pPrm,double currentPos,double targetPos,double targetVel,double runTime,double *pRunPos);


/*-----------------------------------------------------------*/
/* ��Բ�岹ָ��                                              */
/*-----------------------------------------------------------*/

#define ELLIPSE_AUX_POINT_COUNT                 (5)

#define ELLIPSE_MODE_AUX_POINT                  (0)
#define ELLIPSE_MODE_STANDARD                   (1)

#define ELLIPSE_MODE_AUX_POINT_2D               (0)
#define ELLIPSE_MODE_STANDARD_2D                (1)

typedef struct
{
	double pos[ELLIPSE_AUX_POINT_COUNT][INTERPOLATION_AXIS_MAX];    // ��Բ�ϸ���������
}TEllipseAuxPoint;

typedef struct
{
	double centerPoint[INTERPOLATION_AXIS_MAX];// ��ԲԲ������
	double theta;                              // ��Բ��ת�Ƕ�
	double a;                                  // ��Բ����
	double b;                                  // ��Բ����
}TEllipseStandard;

typedef union
{
	TEllipseAuxPoint auxPoint;                 // ������ģʽ����
	TEllipseStandard standard;                 // ��׼ģʽ����

	double reserve[60];
} TEllipseParameterUnion;

typedef struct
{
	double endPoint[INTERPOLATION_AXIS_MAX];   // �յ�����
	short plane;                               // ��Բƽ��ѡ��0��XY��1��YZ��2��ZX
	short dir;                                 // ��Բ����0��˳ʱ�룻1����ʱ��
	short overrideSelect;                      // �ٶȱ���ѡ��0����1�鱶�ʣ�1����2�鱶��
	short mode;                                // ��Բģʽ��Ŀǰֻ֧�ֲ���0(������ģʽ)

	TEllipseParameterUnion data;               // ��������
} TEllipseParameter;

//-------------------------------------------------------
//����˵������Բ�岹��������,ģʽ��ELLIPSE_MODE_AU_POINT_2D
//plane--------------��Բƽ��ѡ��INTERPOLATION_CIRCLE_PLAT_XY(0)��XY��INTERPOLATION_CIRCLE_PLAT_YZ(1)��YZ��INTERPOLATION_CIRCLE_PLAT_ZX(2)��ZX
//dir----------------��Բ����0��˳ʱ�룻1����ʱ��
//overrideSelect-----�ٶȱ���ѡ��0����1�鱶�ʣ�1����2�鱶��
//pad----------------ռλ����������Ҫ����
//endPoint1----------�յ�����1,�������plane���������palneΪXYƽ�棬��endPoint1��pos1ΪX���꣬endPoint2��pos2ΪY����
//endPoint2----------�յ�����2
//pos1---------------��Բ�ϸ���������1
//pos2---------------��Բ�ϸ���������2
//-------------------------------------------------------
typedef struct
{
	short plane;
	short dir;
	short overrideSelect;
	short pad;

	double endPoint1;
	double endPoint2;

	double pos1[ELLIPSE_AUX_POINT_COUNT];
	double pos2[ELLIPSE_AUX_POINT_COUNT];
} TEllipseAuxPoint2D;

//-------------------------------------------------------
//����˵������Բ�岹��������,ģʽ��ELLIPSE_MODE_STANDARD_2D
//plane--------------��Բƽ��ѡ��INTERPOLATION_CIRCLE_PLAT_XY(0)��XY��INTERPOLATION_CIRCLE_PLAT_YZ(1)��YZ��INTERPOLATION_CIRCLE_PLAT_ZX(2)��ZX
//dir----------------��Բ����0��˳ʱ�룻1����ʱ��
//overrideSelect-----�ٶȱ���ѡ��0����1�鱶�ʣ�1����2�鱶��
//pad----------------ռλ����������Ҫ����
//endPoint1----------�յ�����1,�������plane���������palneΪXYƽ�棬��endPoint1ΪX���꣬endPoint2ΪY����
//endPoint2----------�յ�����2
//centerPoint1-------��ԲԲ������1���������plane���������palneΪXYƽ�棬��centerPoint1ΪX���꣬centerPoint2ΪY����
//centerPoint2-------��ԲԲ������2
//theta--------------��Բ��ת�Ƕȣ���λ����
//a------------------��Բ����
//b------------------��Բ���ᣬ�������ȳ����
//-------------------------------------------------------
typedef struct
{
	short plane;
	short dir;
	short overrideSelect;
	short pad;

	double endPoint1;
	double endPoint2;

	double centerPoint1;
	double centerPoint2;

	double theta;
	double a;
	double b;
}TEllipseStandard2D;

GT_API GTN_Ellipse(short core,short crd,TEllipseParameter *pEllipse,double synVel,double synAcc,double velEnd,long segNum,short fifo=0);
GT_API GTN_EllipseEx(short core,short crd,TEllipseParameter *pEllipse,double synVel,double synAcc,double velEnd,long segNum,short fifo=0);

GT_API GTN_EllipsePro(short core,short crd,short mode,void *pData,double synVel,double synAcc,double velEnd,long segNum,short fifo=0);
GT_API GTN_EllipseProEx(short core,short crd,short mode,void *pData,double synVel,double synAcc,double velEnd,long segNum,short fifo=0);

// ��������غ���
#define MC_HEIGHT_FEEDBACK				(450)
// ���á���ȡ���������Ʋ���
typedef struct
{
	short active;				// ʹ�����в������������Ƶ�ʡ�
	short ctlMode;				// �߶ȱջ����ƻ��ǿ�������
	short linkTableId;			// ʹ�����ű��ֵ
	short controlEncoder;		// ��ֵ��Դ�ڵڼ�·�߶ȴ�����
	short interval;				// �������ʱ�䣬�ж�����Ϊ��λ��
	long errorLimit;			// �������,��������ģʽ����Ч
}THeightControlPrm;

GT_API GTN_SetAxisHeightControlPrm(short core,short axis,THeightControlPrm *pPrm);
GT_API GTN_GetAxisHeightControlPrm(short core,short axis,THeightControlPrm *pPrm);

// ���á���ȡ��������ֵ��
GT_API GTN_SetHeightInterpolationTable(short core,short tableId,long n,double *pPosEnc,double *pPosHeight);
GT_API GTN_GetHeightInterpolationTable(short core,short tableId,long n,double *pPosEnc,double *pPosHeight,long *pRealCount);


typedef struct
{
	short type;					// �ο������Ǳ�����λ�û��ǹ滮λ�û��ǵ��ݸ߶�
	short index;				// ���������߹滮������
	long  crossPos;				// �������߹رո��湦�ܵĴ�Խ�߶�
	short dir;					// �������߹رյĴ�Խ����
	short pad1[3];
}THeightCrossPrm;

typedef struct
{
	short keepEnable;				// 0:�˶���ָ���߶�,1:�˶���ָ���߶Ⱥ󣬱��ָ߶ȸ���
	short pad1[3];
	THeightCrossPrm enableData;		// �Զ������߶ȸ������
	THeightCrossPrm disableData;	// �Զ��رո߶ȸ������
}THeightFollowPrm;

#define HEIGHT_DIR_CROSS_POSITIVE            (1)
#define HEIGHT_DIR_CROSS_NEGATIVE            (2)
#define HEIGHT_DIR_CROSS_EQUAL               (3)

#define HEIGHT_FOLLOW_ENABLE_MODE_MANUAL						(0)
#define HEIGHT_FOLLOW_ENABLE_MODE_AUTO							(1)
// �Զ�����/�رո��湦�ܻ���Ӧ�ó����������߹رո߶ȸ��湦��
GT_API GTN_SetAxisHeightFollowMode(short core,short axis,short mode,THeightFollowPrm *pPrm);


// ������λ�ø��湦�ܴ򿪡��ر�
GT_API GTN_AxisHeightControlEnable(short core,short axis,short enable,long pos=10);
// ��ȡ������λ��
GT_API GTN_GetHeightInterpolationPos(short core,short heigtFbIndex,double *pHeightFrq,double *pHeightPosRaw,double *pInterpolationPos);
// ��ȡ������״̬��Ϣ

typedef struct
{
	short ctlMode;			// ��ǰ��ջ�ģʽ������������ջ������ǵ�����Ƶ�ʱջ���
	short errorSts;			// ����״̬��
	double cmpValue;		// ����ֵ
}THeightInf;
GT_API GTN_GetAxisHeightInf(short core,short axis,THeightInf *pHeightInf);
// ���������״̬
GT_API GTN_ClearAxisHeightSts(short core,short axis);

//FIR�˲���
#define HEIGHT_FILTER_TYPE_FREQUENCY			(1)
#define HEIGHT_FILTER_TYPE_CMP_VALUE			(2)
GT_API GTN_GetAxisHeightFrqFilter(short core,short axis,short type,short *pFilterNum);
GT_API GTN_SetAxisHeightFrqFilter(short core,short axis,short type,short filterNum);


// �궨����

#define CALIBRATION_MODE_DIFFERENT_STEP		(1)
// �궨stage
#define DIFFERENT_STEP_CALIBRATION_STAGE_NONE						(-1)//����
#define DIFFERENT_STEP_CALIBRATION_STAGE_HOME_SEARCH				(1)//�������
#define DIFFERENT_STEP_CALIBRATION_STAGE_GO_OFFSET					(2)//�˶�ƫ��
#define DIFFERENT_STEP_CALIBRATION_STAGE_CALIBRATION_INIT			(3)//��ʼ�궨ǰ�ĳ�ʼ��
#define DIFFERENT_STEP_CALIBRATION_STAGE_CALIBRATION				(4)//�궨����
#define DIFFERENT_STEP_CALIBRATION_STAGE_CALIBRATION_DONE			(5)//�궨���
#define DIFFERENT_STEP_CALIBRATION_STAGE_CALIBRATION_STOP			(6)//�궨ֹͣ

#define DIFFERENT_STEP_CALIBRATION_STAGE_HOME_START_ERROR			(100)
#define DIFFERENT_STEP_CALIBRATION_STAGE_HOME_SEARCH_ERROR			(101)
#define DIFFERENT_STEP_CALIBRATION_STAGE_GO_OFFSET_ERROR			(102)
#define DIFFERENT_STEP_CALIBRATION_STAGE_CALIBRATION_ERROR			(103)
#define DIFFERENT_STEP_CALIBRATION_STAGE_NOT_AXIS_ON				(104)
#define DIFFERENT_STEP_CALIBRATION_STAGE_SET_TABLE_ERROR			(105)

// ���궨������
#define DIFFERENT_STEP_CALIBRATION_STEP_MAX							(4000)

#define CALIBRATION_MODE_DIFFERENT_STEP		(1)
#define CALIBRATION_STEP_MAX			(50)

typedef struct
{
	short heightFbIndex;					// �ڼ�·Ƶ������
	short motorEncoder;						// �ڼ�·������
	short pad[2];

	double homeVel;							// ������ٶ� ������/���룩
	double homeDir;							// ������˶�����
	long frqMutationStopValue;				// ����ʱƵ��ͻ��ֹͣ��ֵ
	long offset;							// �������ͣ��ƫ�á���ͣ��λ�ÿ�ʼ�궨��

	double distance;						// �궨���� (���嵥λ��
	double calibrationVel;					// �궨�ٶ�
	double calibrationStepCount;			// �궨����
	double calibrationCountPerStep[CALIBRATION_STEP_MAX];	// ÿ�α궨����
	short tableId;						// �궨�����ݱ���������
}TDifferentStepCalibration;

typedef union
{
	TDifferentStepCalibration differentStep;
}THeightCalibration;

typedef struct
{
	short mode;							// Ŀǰֻ���Ǳ䲽�����Ա궨��CALIBRATION_MODE_DIFFERENT_STEP
	THeightCalibration prm;
}THeightCalibrationPrm;

GT_API GTN_ClearAxisHeightCalibrationSts(short core,short axis);
GT_API GTN_StopAxisHeightCalibration(short core,short axis);
GT_API GTN_RunAxisHeightCalibration(short core,short axis,short *pStage);
GT_API GTN_SetAxisHeightCalibration(short core,short axis,THeightCalibrationPrm *pPrm);

typedef struct
{
	long positiveMutationValue;		// �ӽ�����ʱ��������Ƶ��ͻ������ֵ����������
	short positiveMutationStopLinkLimitType;// �ӽ�����ʱ,Ƶ��ͻ��ֹͣ�������������λ���͡�
	long negativeMutationValue;		//Զ�뵲��ʱ��������Ƶ��ͻ������ֵ����������
	short negativeMutationStopLinkLimitType;// Զ�뵲��ʱ,Ƶ��ͻ��ֹͣ�������������λ���͡�
}TFrqMutationStopPrm;
GT_API GTN_HeightFrqMutationStopEnable(short core,short axis,short enable,TFrqMutationStopPrm *pMutationStopPrm);
GT_API GTN_GetHeightFrqMutationStopEnable(short core,short axis,short *pEnable,TFrqMutationStopPrm *pMutationStopPrm);

GT_API GTN_GoToAxisFollowHeight(short core,short axis,long followCmd,THeightFollowPrm *pFollowPrm,double trapVel,TTrapPrm *pTrapPrm);

GT_API GTN_GetAxisHeightBand(short core,short axis,long *pBand,long *pTime);
GT_API GTN_SetAxisHeightBand(short core,short axis,long band,long time);

#define HEIGHT_FINDEDGE_LATCH_MAX   4
typedef struct
{
	short type;
	short moveAxis;
	short latchNum;
	short reserve1;
	short latchType[HEIGHT_FINDEDGE_LATCH_MAX];
	short latchIndex[HEIGHT_FINDEDGE_LATCH_MAX];
	long  heightDiff;
	long reserve2;
	double findTime;
}THeightFindEdgePrm;

typedef struct
{
	short findEdgeSts;
	short error;
	double latchValue[HEIGHT_FINDEDGE_LATCH_MAX];
}THeightFindEdgeResult;

GT_API GTN_SetHeightFindEdgePrm(short core,short heightFbIndex,THeightFindEdgePrm *pFindEdgePrm);
GT_API GTN_GetHeightFindEdgeResult(short core,short heightFbIndex,THeightFindEdgeResult *pFindEdgeResult);
GT_API GTN_GetHeightFindEdgeCoef(short core,short heightFbIndex,double* alpha,double* beta);
GT_API GTN_CloseHeightFindEdge(short core,short heightFbIndex);
GT_API GTN_SetHeightFindEdgeStopMask(short core,short heightFbIndex,long mask,long option);
GT_API GTN_GetHeightFindEdgeStopMask(short core,short heightFbIndex,long* mask,long* option);

typedef struct
{
	double vel;			// �����ٶ�
	double acc;			// �������ٶ�
	double dec;			// �������ٶ�
	double smoothTime;  // ƽ��ʱ��

	double safetyVel;	// �˶�����ȫ���ո߶�ʱ���ٶ�

	short slaveType;					// ��������͡�
	short slaveIndex;					// �����Ӧ��������
	long followCmd;		// ����߶�
	short followEnable;	// �˶�������߶��Ƿ񱣳֡�
	short enable;		// ����ʹ��
	short reserve1[2];
	double reserve2[4];
}TSetAxisLeapFrogPrm;
GT_API GTN_SetAxisLeapFrogPrm(short core,short axis,TSetAxisLeapFrogPrm* pAxisLeapFrogPrm);

GT_API GTN_SetCrdStopMode(short core,short crd,short stopMode);
GT_API GTN_GetCrdStopMode(short core,short crd,short *pStopMode);

typedef struct
{
	double synDistance;		// ��ǰ�κϳɾ���
	double movedsynDistance;	// ��ǰ�����˶���ɵľ���
	double reserve1[10];		// ����
}TCrdMoveInfo;
GT_API GTN_GetCrdMoveInfo(short core,short crd,TCrdMoveInfo *pCrdMoveInfo,short fifo=0);

GT_API GTN_OpenSimulation(short core,double time,double ratio);
GT_API GTN_CloseSimulation(short core);
GT_API GTN_GetSimulationStatus(short core,short *pSts);

//-------------------------------------------------------------------------------------------------
// ·����������
//-------------------------------------------------------------------------------------------------
// ·��������ṹ��
typedef struct
{
	double pos[2];                               // x�ᡢy��λ��
	double compensateValue;	                     // z�Ჹ��λ��
}TCompensatePathPoint;

// ·��������ṹ��
typedef struct
{
	short tableIndex;                            // ·������������
	short axisType[2];                           // ��ѯ·��������X��Y����λ�����ͣ�MC_PROFILE:�滮λ�� MC_ENCODER:������λ��
	short axisIndex[2];                          // ��ѯ·��������X��Y������ʹ�õ����						
	short reserve1[3];                            // ����ֵ������Ϊ0
	double offset[2];                            // x�ᡢy��ƫ��
	double compensateVelMax;                     // ����ֵ�仯������ٶ� ����λ��pulse/ms�����ڣ�1����������ʱ����������ֵ�Ĺ��̣�2����������������ʱ������ֵ�仯�Ĺ���
	double approachRadius;                       // ������ʼ��Ͳ����յ����Ч����뾶
	double workBand;                             // ��������ʱ������
	double workHeight;                           // z�Ṥ���߶�
	double reserve2[2];							 // ����ֵ������Ϊ0
}TCompensatePathParameter;

// ·������״̬�ṹ��
typedef struct{
	short enable;								 // ·������ʹ�ܱ�־
	short state;								 // ·������״̬
	short errorStatus;                           // ·�������Ƿ񳬳�errorBand  0:δ�������� 1����������
	short pointIndex;                            // ·��������ǰ��Ĳ����������
	double compensateStartPos[2];                // ·��������ǰ��Ĳ������λ��
	double compensateValue;                      // ·��������ǰ��Ĳ�����
	double reserve1[2];                          // ����ֵ��Ϊ0
}TCompensatePathStatus;

// ����·��������
GT_API GTN_SetCompensatePathTable(short core,short tableIndex, TCompensatePathPoint *pCompensatePathPoint, short pointCount);
// ����·����������
GT_API GTN_SetCompensatePathParameter(short core,short axis, TCompensatePathParameter *pCompensatePath);
// ��ȡ·����������
GT_API GTN_GetCompensatePathParameter(short core,short axis, TCompensatePathParameter *pCompensatePath);
// ����·������
GT_API GTN_StartCompensatePath(short core,short axis, short startMode = 0, void* pParameter = NULL);
// �ر�·������
GT_API GTN_StopCompensatePath(short core,short axis, short stopMode = 0, void* pParameter = NULL);
// ��ȡ·������״̬
GT_API GTN_GetCompensatePathStatus(short core,short axis, TCompensatePathStatus *pCompensatePathStatus);

/*-----------------------------------------------------------*/
/* ����ͨѶָ�����485/232ͨ��ָ�  (������gt_rn.lib�����Ƽ�ʹ��)*/
/*-----------------------------------------------------------*/
short GT_RN_ComOpen(short index);
short GT_RN_ComClose(short index);
short GT_RN_ComRead(short index, unsigned long readLen, unsigned long* pResLen, unsigned char * pData);
short GT_RN_ComWrite(short index, unsigned long writeLen , unsigned long* pResLen, unsigned char * pData);
short GT_RN_ComGetState(short index, unsigned char * pState);
short GT_RN_ComSetSettings(short index, unsigned long baudrate, unsigned char stopBits, unsigned char parity);
short GT_RN_ComClearErr(short index, unsigned char flag);
short GT_RN_ComSetMode(short index,unsigned short comMode);


/*-----------------------------------------------------------*/
/* ����ͨѶָ�ͨ��485/232ͨ��ָ�(������gt_rn.lib�����Ƽ�ʹ��)*/
/*-----------------------------------------------------------*/
short GTN_RN_SerialComOpen(short cardIndex, short stationphyId, short comIndex);
short GTN_RN_SerialComClose(short cardIndex, short stationphyId, short comIndex);
short GTN_RN_SerialComRead(short cardIndex, short stationphyId, short comIndex, unsigned long readLen, unsigned long* pResLen, unsigned char * pData);
short GTN_RN_SerialComWrite(short cardIndex, short stationphyId, short comIndex, unsigned long writeLen , unsigned long* pResLen, unsigned char * pData);
short GTN_RN_SerialComGetState(short cardIndex, short stationphyId, short comIndex, unsigned char *pState);
short GTN_RN_SerialComSetSettings(short cardIndex, short stationphyId, short comIndex, unsigned long baudrate,unsigned char stopBits, unsigned char parity);
short GTN_RN_SerialComClearErr(short cardIndex, short stationphyId, short comIndex, unsigned char flag);
short GTN_RN_SerialComSetMode(short cardIndex, short stationphyId, short comIndex, unsigned short comMode);

//��ȡ���縨��������
GT_API GTN_RN_GetRemotAuEncPos(short cardIndex, short stationPhyId, short auEncIndex,double *pAuEncPos,short anEncCount);

//-------------------------------------------------------------------------------------------------------
//��ȡ��ģ��LED��ʾģʽ
//GTN_RN_ReadLedDispalyMode(short cardIndex, short stationPhyId, unsigned char *pMode, unsigned char *pRadix)
// mode:�ư��������ʾģʽ�� 
//0������ģʽ(�ϵ��ʼ״̬��ʾ�㣬��ʹ�ܺ���ʾС���㣬�����л���ʽ����)��  
//1��վ��ģʽ(��ʾվ�ţ�������ʾ����䶯)��  
//2������ģʽ(Ԥ��)��
//radix:�ư��������ʾ���ƣ� 0�������ƣ�  1���˽��ƣ�  2��ʮ���ƣ�  3��ʮ�����ƣ�
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_ReadLedDispalyMode(short cardIndex, short stationPhyId, unsigned char *pMode, unsigned char *pRadix);
//-------------------------------------------------------------------------------------------------------
//������ģ��LED��ʾģʽ
//GTN_RN_WriteLedDisplayMode(short cardIndex, short stationPhyId, unsigned char mode, unsigned char radix)
// mode:�ư��������ʾģʽ�� 
//0������ģʽ(�ϵ��ʼ״̬��ʾ�㣬��ʹ�ܺ���ʾС���㣬�����л���ʽ����)��  
//1��վ��ģʽ(��ʾվ�ţ�������ʾ����䶯)��  
//2������ģʽ(Ԥ��)��
//radix:�ư��������ʾ���ƣ� 0�������ƣ�  1���˽��ƣ�  2��ʮ���ƣ�  3��ʮ�����ƣ�
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_WriteLedDisplayMode(short cardIndex, short stationPhyId, unsigned char mode, unsigned char radix);
//-------------------------------------------------------------------------------------------------------
//�����ŷ�����
//GTN_RN_ExportServoParams(short cardIndex, short stationPhyId, short axis, char *pFilePath, char *pFileName)
// cardIndex:��1��ʼ
// stationPhyId:��0��ʼ
// axis:���
// pFilePath��ģ���ļ���·��
// pFileName���������ļ�·��������
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_ExportServoParams(short cardIndex, short stationPhyId, short axis, char *pFilePath, char *pFileName);
//-------------------------------------------------------------------------------------------------------
//�����ŷ�����
//GTN_RN_ImportServoParams(short cardIndex, short stationPhyId, short axis, char *pFilePath, char *pFileName)
// cardIndex:��1��ʼ
// stationPhyId:��0��ʼ
// axis:���
// pFilePath��ģ���ļ���·��
// pFileName���������ļ�·��������
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_ImportServoParams(short cardIndex, short stationPhyId, short axis, char *pFilePath, char *pFileName);


//��ȡ��ֹͣ��ϸ��Ϣ����
GT_API GTN_GetAxisStopInfo(short core,short axis,long *pInfo,double *pPos,short count=1);
GT_API GTN_ClearAxisStopInfo(short core,short axis,short count=1);
GT_API GTN_SetAxisStopInfoMode(short core,short axis,short *pMode,short count);
GT_API GTN_GetAxisStopInfoMode(short core,short axis,short *pMode,short count);

//-------------------------------------------------------------------------------------------------------
// ���ݲɼ����ܣ����������ļ�
// cardIndex:��1��ʼ
// stationPhyId:��0��ʼ
// pFileName���������ļ�·��������
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_LoadFileConfig(short cardIndex,short stationPhyId,char *pFileName);
//-------------------------------------------------------------------------------------------------------
// ���ݲɼ����ܣ�����DMA���ݲɼ�
// cardIndex:��1��ʼ
// stationPhyId:��0��ʼ
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_HighSpeedSamplingOnAll(short cardIndex,short stationPhyId);
//-------------------------------------------------------------------------------------------------------
// ���ݲɼ����ܣ��ر�DMA���ݲɼ�
// cardIndex:��1��ʼ
// stationPhyId:��0��ʼ
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_HighSpeedSamplingOffAll(short cardIndex,short stationPhyId);
//-------------------------------------------------------------------------------------------------------
// ���ݲɼ����ܣ���ȡ�ɼ�����
// cardIndex:��1��ʼ
// stationPhyId:��0��ʼ
// pData�����ݷ��أ��û���Ҫ���������
// dataCount��������Ҫ�ض������ݸ�����ȡֵ��Χ[0,4096]
// pResDataCount������ʵ�ʶ��������ݸ���
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_HighSpeedSamplingGetAllData(short cardIndex,short stationPhyId,unsigned short *pData,unsigned long dataCount,unsigned long *pResDataCount);

//��ȡ�������ֵ������
typedef struct 
{
	short stationId;
	short axis;
	unsigned long long multiLines;
	double pos;
}StAbsEncPos;
GT_API GTN_RN_GetMultiAbsEncPos(short cardIndex,StAbsEncPos* pStAbsEncPos,short count);

//-------------------------------------------------------------------------------------------------------
// ��ʼ��PC��DLL Buffer��С
// cardIndex:��1��ʼ
// stationPhyId:��0��ʼ
// bufferAddrWidth������DLL Buffer�Ŀռ��С
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_ScanCmpInitialWrBuffer(short cardIndex, short stationPhyId, unsigned short bufferAddrWidth);
//-------------------------------------------------------------------------------------------------------
// ��ȡ��ǰDLL Buffer�е���Ч�������ͻ��ж���ʣ��ռ����д��
// cardIndex:��1��ʼ
// stationPhyId:��0��ʼ
// pValidWordNum����ǰDLL Buffer���ж���word�ռ�����ݣ�û�з��͵���ģ��
// pRemainsWordSpase: ��ǰDLL Buffer���ж���word�ռ�����ݣ������û�д��
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_ScanCmpGetWrBufferStatus(short cardIndex, short stationPhyId, unsigned long *pValidWordNum, unsigned long *pRemainsWordSpase);
//-------------------------------------------------------------------------------------------------------
// ������д��DLL Buffer��
// cardIndex:��1��ʼ
// stationPhyId:��0��ʼ
// pData��Ҫд�������ָ��
// pWordNumVaild: ����д������ݵ�word�ĸ���
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_ScanCmpWrBufferData(short cardIndex, short stationPhyId, unsigned short *pData, unsigned long wordNum, unsigned long *pWordNumVaild);
//-------------------------------------------------------------------------------------------------------
// ������ģ���buffer״̬����DLL Buffer�е����ݶ�ȡ�����µ���ģ�黺������
// cardIndex:��1��ʼ
// stationPhyId:��0��ʼ
// dataType����Ҫѹ�뻺��������������: 0��SCAN�����������1��CMP��λ�ñȽ��������
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_ScanCmpUpdateBufferDataToFPGA(short cardIndex, short stationPhyId, short dataType);
//-------------------------------------------------------------------------------------------------------
// ʹ����ģ�黺������ʹ�ܺ���ģ���ָ�������ȡָ�ֻӦ�����񾵣�
// cardIndex:��1��ʼ
// stationPhyId:��0��ʼ
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_ScanEnableFifo(short cardIndex, short stationPhyId);
//-------------------------------------------------------------------------------------------------------
// �ر���ģ�黺�������رպ���ģ����ͣ�ӻ�������ȡָ�ֻӦ�����񾵣�
// cardIndex:��1��ʼ
// stationPhyId:��0��ʼ
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_ScanDisableFifo(short cardIndex, short stationPhyId);
//-------------------------------------------------------------------------------------------------------
// ���������ڲ�������ȡ��xml�ļ���
// cardIndex:		    ����
// stationPhyId:        վ��
// path:                ��Ҫд���xml�ļ�·��+����
// tpfUpdataProgressPt: �ص�������������¼��ȡ������xml�ļ�����
// ptrv:                �ص�����tpfUpdataProgressPt��һ������
// progress:            �ص�����tpfUpdataProgressPt�ڶ��������� ��ʾ����
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_UploadServoParaFile(short cardIndex, short stationPhyId, char *path, void(*tpfUpdataProgressPt)(void*, short*), void* ptrv, short& progress);
//-------------------------------------------------------------------------------------------------------
// ��xml�ļ�����д��������
// cardIndex:		    ����
// stationPhyId:        վ��
// path:                ��Ҫд���xml�ļ�·��+����
// tpfUpdataProgressPt: �ص�������������¼��ȡ������xml�ļ�����
// ptrv:                �ص�����tpfUpdataProgressPt��һ������
// progress:            �ص�����tpfUpdataProgressPt�ڶ��������� ��ʾ����
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_DownloadServoParaFile(short cardIndex,  short stationPhyId, char* path, void(*tpfUpdataProgressPt)(void*, short*), void* ptrv, short& progress);
//-------------------------------------------------------------------------------------------------------
// ��ȡ������������
// cardIndex:		    ����
// stationPhyId:        վ��
// progress:            ��ȡ���Ľ���,ȡֵ��Χ[0..100]
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_UpdateProgress(short cardIndex, short stationPhyId, unsigned short progress);

//-------------------------------------------------------------------------------------------------------
// �����˲���������
// cardIndex:		    ����
// stationPhyId:        վ��
// fltLength:           ����ƽ���˲�������Ĭ��ֵ100�����㷽ʽ��fltLength = 0.443*����Ƶ��/��ֹƵ��
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_SamplingFilterSet(short cardIndex, short stationPhyId, short fltLength);

//-------------------------------------------------------------------------------------------------------
// �����˲�������ȡ
// cardIndex:		    ����
// stationPhyId:        վ��
// fltLength:           ��ȡ���Ļ���ƽ���˲�������Ĭ��ֵ100�����㷽ʽ��fltLength = 0.443*����Ƶ��/��ֹƵ��
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_SamplingFilterGet(short cardIndex, short stationPhyId, short *pFltLength);

typedef struct TPvtLinePrm
{
	short mode;  //������Чģʽ
	short smoothTimer;  //ƽ��ʱ��
	long moveTime;  //�˶�ʱ��
	long pad;       //����λ
	double synVel;   //�ϳ�Ŀ���ٶ�
	double synAcc;  //�ϳɼ��ٶ�
	double synJeck; //�ϳɼӼ��ٶ�
}TPvtLinePrm;
GT_API GTN_PvtLine(short core,short axisCount,short *moveAxis,long *pos,TPvtLinePrm *pPrm);

GT_API GTN_GetTerminalLinkCount(short core,unsigned short *pTerminalLinkCount);

/*-----------------------------------------------------------*/
/* ���ܹ���	                                            		*/
/*-----------------------------------------------------------*/
typedef struct
{
	char uuid[32];		// ԭʼ��Կ
	char mcInf[32];		//
}TEncryptConfigPrm;

typedef struct
{
	char keyValue[32];		// ��Կ
	char data[32];			// ��ȡ���Ļ���д��ȥ���µ�����
}TEncryptData;

typedef struct
{
	short type;					// оƬ����
	short userKeySlotOffset;		// ��Կ��ƫ��
	short userDataSlotOffset;		// ���ݲ�ƫ��
	short cardType;		// ���ƿ�����
	short reverse1[8];
}TEncryptChipInf;

typedef struct
{
	char sn[9];				// оƬ���к�
	char random[32];		// ���ص������
	TEncryptChipInf chipInf;	// оƬ������Ϣ
}TEncryptAuxInf;

typedef struct
{
	char data[32];			// ��ȡ���ļ�������
	char hMac[32];			//
}TEncryptDataPro;

GT_API GTN_SetEncryptConfig(short core,TEncryptConfigPrm *pConfigPrm, short *pSts);
// �����汾���ܹ���
//  ���ܶ�д����
GT_API GTN_GetEncryptData(short core,TEncryptData *pReadPrm);
GT_API GTN_SetEncryptData(short core,TEncryptData *pWritePrm);
// �����汾�����Ž��ܺ������û����ݶ�ȡ�����ġ����õ���Կ����
GT_API GTN_GetEncryptAuxInf(short core,TEncryptAuxInf *pAuxInf,short *pSts);
GT_API GTN_SetEncryptDataPro(short core,short slotIndex,short block,TEncryptDataPro *pWritePrm,short *pSts);
GT_API GTN_GetEncryptDataPro(short core,short slotIndex,short block,TEncryptDataPro *pReadPrm,short *pSts);

// �����汾��������Կ
typedef struct
{
	char oldKey[32];		// ԭʼ��Կ
	char newKey[32];		// ����Կ
}TEncryptKey;

GT_API GTN_UpdateEncryptKey(short core,short keyIndex,TEncryptKey *pKeyInf,short *pSts);

typedef void(WINAPI* TCallbackFunction)(const short data[256]);
GT_API GTN_SetCallbackFunctionParameter(short core,TCallbackFunction callbackFunction);
GT_API GTN_StopCallbackFunction(short core);

GT_API GTN_RN_ReadEEPROM(short cardIndex, short stationPhyId, short axis, unsigned short ofst, unsigned char* pValue, unsigned short num);
GT_API GTN_RN_WriteEEPROM(short cardIndex, short stationPhyId, short axis, unsigned short ofst, unsigned char* pValue, unsigned short num);
GT_API GTN_RN_ResetServoDSP(short cardIndex, short stationPhyId, short axis);
GT_API GTN_ResetServoDSP(short core, short axis);
GT_API GTN_RN_WriteSetId(short cardIndex, short stationPhyId, short setId);
GT_API GTN_RN_ReadSetId(short cardIndex, short stationPhyId, short *pSetId);
GT_API GTN_RN_DisableSetId(short cardIndex, short stationPhyId);
GT_API GTN_RN_FORWrite(short cardIndex,short stationPhyId, short* pData, unsigned long dataCount, unsigned long* pDataCount, char* pFileName);
GT_API GTN_RN_SetStationSlotResourceEx( short cardIndex, short stationPhyId, char* pFileName, short slotInfo);
//�岹��������չģ��ָ��
GT_API GTN_BufExtIO(short core,short crd,unsigned short doIndex,unsigned short doMask,unsigned short doValue,short fifo);
GT_API GTN_BufExtDA(short core,short crd,short chn,short daValue,short fifo);
GT_API GTN_BufExtAoEx(short core,short crd,short aoIndex,double aoValue,short fifo);
GT_API GTN_BufExtDoBitEx(short core,short crd,unsigned short doIndex,unsigned short doValue,short fifo);
GT_API GTN_BufExtDoBit(short core,short crd,unsigned short doIndex,unsigned short doValue,short fifo);
GT_API GTN_BufExtAo(short core,short crd,short aoIndex,double aoValue,short fifo);
GT_API GTN_GetCoreInfo(short cardIndex, short* pCoreIndex, short* pCoreCount, short* pCoreValidFlag, short cardCount);
typedef struct
{
	short resType;//ʵ����Դ����
	short resIndex;//ʵ����Դ���
	//short mapType;
	short mapIndex;
	short mapCount;
} TResTypeMapInfo;
typedef struct
{
	short resMapType;//�߼���Դ����
	short resMapCount;//�߼���Դ����
	TResTypeMapInfo resmapInfo[64];//ÿ����Դ�����resMap���
} TTerminalResMapInfo;
typedef struct
{
	short netType;
	unsigned short terminalType;
	short terminalSubType;
	short phyId;
	short slotCount;
	unsigned short slotType[16];
	short stationResMapCount;
	TTerminalResMapInfo terminalResMapInfo[64];//ÿ��վ�������Դ����
} TTerminalInfo;
GT_API GTN_GetTerminalInfo(short core,short index,TTerminalInfo *pTerminalInfo);

//-------------------------------------------------------------------------------------------------------
// ���ñ�����ID
// cardIndex:		����
// stationPhyId:    վ�ţ���0��ʼ
// regionId:        ��Ҫд��ı�����ID��ȡֵ��Χ[0..15]������֮ǰĬ��Ϊ240��
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_SetLocalHubID(short cardIndex, short stationPhyId, short regionId);

//-------------------------------------------------------------------------------------------------------
// ��ȡ������ID
// cardIndex:		����
// stationPhyId:    վ�ţ���0��ʼ
// pRegionId:       ��ȡ���ı�����ID��ȡֵ��Χ[0..15]
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_GetLocalHubID(short cardIndex, short stationPhyId, short *pRegionId);

//-------------------------------------------------------------------------------------------------------
// ����������hub��Ϣ
// cardIndex:		����
// stationPhyId:    վ�ţ���0��ʼ
// regionLocalId:   ���ñ�����ID��ȡֵ��Χ[0..15]
// pRegionID:       ���������д��ڵ���ID�� ȡֵ��Χ[0..15]
// regionNums:      ������������ĸ�����ȡֵ��Χ[0..16]
// comByteSize:     ������֮���ͨ���ֽ���(bytes)��ȡֵ��Χ[0..240]
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_SetMultiHubCfgInfo(short cardIndex, short stationPhyId, short regionLocalId, short* pRegionID, short regionNums, short comByteSize);

//-------------------------------------------------------------------------------------------------------
// ��ȡ������hub��Ϣ
// cardIndex:		����
// stationPhyId:    վ�ţ���0��ʼ
// pRegionLocalId:  ��ȡ������ID��ȡֵ��Χ[0..15]
// pRegionID:       ��ȡ�����д��ڵ���ID�� ȡֵ��Χ[0..15]
// pRegionNums:     ��ȡ��������ĸ�����ȡֵ��Χ[0..16]
// pComByteSize:    ��ȡ��֮���ͨ���ֽ���(bytes)��ȡֵ��Χ[0..240]
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_GetMultiHubCfgInfo(short cardIndex, short stationPhyId, short *pRegionLocalId, short* pRegionID, short* pRegionNums, short *pComByteSize);

//-------------------------------------------------------------------------------------------------------
// д���ݵ�Ŀ����
// cardIndex:		����
// stationPhyId:    վ�ţ���0��ʼ
// regionId:        д���Ŀ����ID��ȡֵ��Χ[0..15]
// pData:           д�������
// byteOffset:      д�����ݵĵ�ַƫ�ã���ֵΪ4�ı�����ȡֵ��Χ[0..240]
// byteNum:         Ҫд��������ֽ�������ֵΪ4�ı�����ȡֵ��Χ[0..240]
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_MultiHubPcComWr(short cardIndex, short stationPhyId, short regionId, unsigned char* pData, unsigned short byteOffset, unsigned short byteNum);

//-------------------------------------------------------------------------------------------------------
// ��Ŀ�����ȡ����
// cardIndex:		����
// stationPhyId:    վ�ţ���0��ʼ
// regionId:        д���Ŀ����ID��ȡֵ��Χ[0..15]
// pData:           д�������
// byteOffset:      д�����ݵĵ�ַƫ�ã���ֵΪ4�ı�����ȡֵ��Χ[0..240]
// byteNum:         Ҫд��������ֽ�������ֵΪ4�ı�����ȡֵ��Χ[0..240]
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_MultiHubPcComRd(short cardIndex, short stationPhyId, short regionId, unsigned char* pData, unsigned short byteOffset, unsigned short byteNum);

//-------------------------------------------------------------------------------------------------------
// ��ȡEeprom���ݡ�
// cardIndex:		����
// stationPhyId:    վ�ţ���0��ʼ
// ofst:            ��Ҫ��ȡ��Eeprom��ַ
// pValue:          ��ȡ����ֵ
// num:             ��Ҫ��ȡ�ĸ���
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_ReadEepromData(short cardIndex, short stationPhyId, unsigned short ofst, unsigned char* pValue, unsigned short num);

//-------------------------------------------------------------------------------------------------------
// д��Eeprom���ݡ�
// cardIndex:		����
// stationPhyId:    վ�ţ���0��ʼ
// ofst:            ��Ҫд���Eeprom��ַ
// pValue:          ��Ҫд���ֵ
// num:             ��Ҫд��ĸ���
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_WriteEepromData(short cardIndex, short stationPhyId, unsigned short ofst, unsigned char* pValue, unsigned short num);

//-------------------------------------------------------------------------------------------------------
// ��ȡ������Դ������Ϣ
// cardIndex:		����
// stationPhyId:    վ�ţ���0��ʼ
// slotInfo:        [15--8]��ʾ�忨���ͣ� 1: �װ壻2���Ӱ壻3��ͨѶ�� [7--0]��ʾ�忨��ţ��߰�λΪ1(�װ�)ʱ��ȡֵ��Χ 1���߰�λΪ2���Ӱ壩ʱ��ȡֵ��Χ[1..7]; �߰�λΪ3��ͨѶ�壩ʱ��ȡֵ��Χ 1
// mcDef:           ��Դ�궨�壬��ϸ˵���ο���¼I 
// pData:           ��ȡ������Դֵ��16λ��ֵ��
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_GetStationSlotResourceEx(short cardIndex, short stationPhyId, short slotInfo, short mcDef, unsigned short *pData);

GT_API GTN_RN_GetStationInfomation(short cardIndex, short stationPhyId, unsigned char infoType, unsigned char infoCount, unsigned long* pInfo);

//-------------------------------------------------------------------------------------------------------
// 500���������������л�����cpu��Ilinkģ�����Ȩ��Ĭ�ϴ�cpu�ɿأ���cpu��ģ�鷢����ʱ������Ȩ�л�����cpu
// cardIndex:		����
// stationPhyId:    վ�ţ���0��ʼ
// moduleId:        Ilinkģ��Id��ȡֵ��Χ[0..63]
// data:            д������ֵ��bit0����0��1��ת������10ms����ת����Ϊû����������
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_IlinkSetHeartbeat(short cardIndex, short stationPhyId, short moduleId, unsigned short data);

//-------------------------------------------------------------------------------------------------------
// 500��������CPUͨ��д
// cardIndex:		����
// stationPhyId:    վ�ţ���0��ʼ
// dataCount:       һ��ͨѶд���������������ȡֵ��Χ[1..256]dword
// data:            д�������
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_IlinkPcComWr(short cardIndex, short stationPhyId, unsigned short dataCount, unsigned long* data);

//-------------------------------------------------------------------------------------------------------
// 500��������CPUͨ�Ŷ�
// cardIndex:		����
// stationPhyId:    վ�ţ���0��ʼ
// dataCount:       һ��ͨѶ��ȡ��������������ȡֵ��Χ[1..256]dword
// data:            ��ȡ��������
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_IlinkPcComRd(short cardIndex, short stationPhyId, unsigned short dataCount, unsigned long* data);

//-------------------------------------------------------------------------------------------------------
// 	��ȡ����������Դ������Ϣ
// cardIndex:		����
// stationPhyId:    վ�ţ���0��ʼ
// pData:           ��ȡ������Դ������Ϣ
// dataCount:       ��Ҫ��ȡ����Դ������Ϣ����
// pResCount:       ʵ�ʻ�ȡ����Դ������Ϣ����
// slotInfo:        [15--8]��ʾ�忨���ͣ�
//  1: �װ壻2���Ӱ壻3��ͨѶ��
//	[7--0]��ʾ�忨��ţ�
//	�߰�λΪ1(�װ�)ʱ��ȡֵ��Χ 1��
//	�߰�λΪ2���Ӱ壩ʱ��ȡֵ��Χ[1..7];
//  �߰�λΪ3��ͨѶ�壩ʱ��ȡֵ��Χ 1
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_GetStationSlotResource(short cardIndex, short stationPhyId, unsigned long* pData, short dataCount, short* pResCount, short slotInfo);

GT_API GTN_RN_WriteResourceTable(short cardIndex, unsigned long *pResDef, short count, char* pData, short* pDataSize);

//-------------------------------------------------------------------------------------------------------
// PC������������˿�
// cardIndex:		    ����
// callBackFun:         �ص�����
// pParamA:             �ص�����������NULL
//-------------------------------------------------------------------------------------------------------
typedef short (*FunCallBack)(void*, long, void*);
GT_API GTN_RN_InitialUserCallBack(short cardIndex,FunCallBack callBackFun, void* pParamA);

//-------------------------------------------------------------------------------------------------------
// PCͨѶд����
// cardIndex:		    ����
// phyStationId:        PCͨѶʱ����Ҫ���ͶԶ˵�ID��������Ͷ�λPC�ˣ�id��ȡֵ��Χ[0,31]��������Ͷ�Ϊ�������ˣ�id=0xF2
// pData:               �ص�����������NULL
// byteNum��            PCͨ���ֽ�����ȡֵ��Χ[0,240]
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_UserOverRnWrite(short cardIndex, short phyStationId, unsigned char* pData, long byteNum);

//-------------------------------------------------------------------------------------------------------
// дphy�Ĵ�����ֵ
// cardIndex:		    ����
// stationPhyId:        վ��
// phyIndex:            phyоƬ������ȡֵ��Χ[1..2]
// phyAddr:             phyоƬ��ַ�� ȡֵ0
// regAddr:             phy�Ĵ�����ַ
// data:               Ҫд��Ĵ�������ֵ
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_WritePhyRegValue(short cardIndex, short stationPhyId, short phyIndex, short phyAddr, short regAddr, short data);

//-------------------------------------------------------------------------------------------------------
// ��phy�Ĵ�����ֵ
// cardIndex:		    ����
// stationPhyId:        վ��
// phyIndex:            phyоƬ������ȡֵ��Χ[1..2]
// phyAddr:             phyоƬ��ַ�� ȡֵ0
// regAddr:             phy�Ĵ�����ַ
// pData:               ��ȡ���ļĴ���ֵ
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_ReadPhyRegValue(short cardIndex, short stationPhyId, short phyIndex, short phyAddr, short regAddr, short* pData);

//-------------------------------------------------------------------------------------------------------
// ��phy�Ĵ�����ֵ
// cardIndex:		    ����
// stationPhyId:        վ��
// phyIndex:            phyоƬ������ȡֵ��Χ[1..2]
// pData:               ��ȡ��״ֵ̬ �����ݶ���Ϊ��
//                      [15]=wr_active/wr_ing(1��ʾ����д����)  
//                      [12:8]=reg_addr(�Ĵ�����ַ)  
//                      [7]=rd_active/rd_ing(1��ʾ���ڶ�����)  
//                      [4:0]=phy_addr(phyоƬ��ַ)
//-------------------------------------------------------------------------------------------------------
GT_API GTN_RN_ReadPhySts(short cardIndex, short stationPhyId, short phyIndex, short* pData);

typedef struct
{
	short stationPhyId;
	short index;
	short type;
} TRemoteChannelPrm;

typedef struct
{
	short enableFlag;
	short occupy;
	short type;
	short index;
	short lastReceiveError;
	short lastSendError;
	unsigned short errorCount;
	unsigned short continueErrorCount;
} TRemoteChannelInfo;

GT_API GTN_GetRemoteChannelResult(short core,double *pValue,short channelIndex,short channelCount);
GT_API GTN_GetRemoteChannelInfo(short core,TRemoteChannelInfo *pInfo,short channelIndex,short channelCount);
GT_API GTN_GetRemoteChannelPrm(short core,TRemoteChannelPrm *pPrm,short channelIndex,short channelCount);
GT_API GTN_SetRemoteChannelPrm(short core,TRemoteChannelPrm *pPrm,short *pChannelIndex,short channelCount);
//---------------------------------------------------------
// LaserPro
//---------------------------------------------------------

// �����ģʽ
#define LASER_ON_MODE_DEFAULT                    (0)

// ����ر�ģʽ
#define LASER_OFF_MODE_POWER_OFF                 (0)  // ����ر�ʱ������Ҳ�ر�
#define LASER_OFF_MODE_POWER_HOLD                (1)  // ����ر�ʱ������������������ֵ

// ������������ģʽ
#define LASER_FOLLOW_MODE_NONE                   (0)  // δ������������
#define LASER_FOLLOW_MODE_RATIO                  (1)  // ������ϵ��������������
#define LASER_FOLLOW_MODE_TABLE                  (2)  // ����������������������
#define LASER_FOLLOW_MODE_DUO_TABLE              (3)  // ˫����������

#define LASER_FOLLOW_POWER_TYPE_DUTY             (0)
#define LASER_FOLLOW_POWER_TYPE_FREQUENCY        (1)
#define LASER_FOLLOW_POWER_TYPE_PULSE_WIDTH      (2)
#define LASER_FOLLOW_POWER_TYPE_VOLTAGE          (3)
#define LASER_FOLLOW_POWER_TYPE_PARALLEL         (4)

// ������������ϳ��ٶ�Դ
#define LASER_FOLLOW_SYNCH_VEL_SOURCE_PROFILE              (0)
#define LASER_FOLLOW_SYNCH_VEL_SOURCE_ENCODER              (1)

typedef struct
{
	double minDuty;                              // ռ�ձ�����������Сֵ��ȡֵ��Χ��[0,100]����λ��%
	double maxDuty;                              // ռ�ձ������������ֵ��ȡֵ��Χ��[0,100]����λ��%
	double minFrequency;                         // Ƶ������������Сֵ��ȡֵ��Χ��[0,1562.5]����λ��kHz
	double maxFrequency;                         // Ƶ�������������ֵ��ȡֵ��Χ��[0,1562.5]����λ��kHz
	double minPulseWidth;                        // ��������������Сֵ��ȡֵ��Χ��[0,65535]����λ��us
	double maxPulseWidth;                        // ���������������ֵ��ȡֵ��Χ��[0,65535]����λ��us
}TLaserPwmPrmPro;

typedef struct
{
	short laserOn;                               // ���⿪�ع��ź�
	short laserEnable;                           // ������Ԥʹ���ź�
	short laserRed;                              // ���������ָʾ�ź�
	short laserPowerLatch;                       // ���������������ź�
	double duty;                                 // ��ǰPWM��ռ�ձ�ֵ����λ��%
	double frequency;                            // ��ǰPWM��Ƶ��ֵ����λ��kHz
	double pulseWidth;                           // ��ǰPWM������ֵ����λ��us
	double voltage;                              // ��ǰ����ģ����ֵ����λ��V
	double parallel;                             // ��ǰ���Ⲣ������ֵ
}TLaserPowerPro;

typedef struct
{
	short laserOn;                               // ���⿪�ع��ź�
	short laserEnable;                           // ������Ԥʹ���ź�
	short laserRed;                              // ���������ָʾ�ź�
	short laserPowerLatch;                       // ���������������ź�
	double duty;                                 // ��ǰPWM��ռ�ձ�ֵ����λ��%
	double frequency;                            // ��ǰPWM��Ƶ��ֵ����λ��kHz
	double pulseWidth;                           // ��ǰPWM������ֵ����λ��us
	double voltage;                              // ��ǰ����ģ����ֵ����λ��V
	double parallel;                             // ��ǰ���Ⲣ������ֵ

	double minDuty;                              // ռ�ձ�����������Сֵ��ȡֵ��Χ��[0,100]����λ��%
	double maxDuty;                              // ռ�ձ������������ֵ��ȡֵ��Χ��[0,100]����λ��%
	double minFrequency;                         // Ƶ������������Сֵ��ȡֵ��Χ��[0,1562.5]����λ��kHz
	double maxFrequency;                         // Ƶ�������������ֵ��ȡֵ��Χ��[0,1562.5]����λ��kHz
	double minPulseWidth;                        // ��������������Сֵ��ȡֵ��Χ��[0,65535]����λ��us
	double maxPulseWidth;                        // ���������������ֵ��ȡֵ��Χ��[0,65535]����λ��us
	double minVoltage;                           // ����ģ������ѹ��Сֵ��ȡֵ��Χ��[0,10]����λ��V
	double maxVoltage;                           // ����ģ������ѹ���ֵ��ȡֵ��Χ��[0,10]����λ��V
	double minParallel;                          // ���Ⲣ��������Сֵ��ȡֵ��Χ��[0,255]
	double maxParallel;                          // ���Ⲣ���������ֵ��ȡֵ��Χ��[0,255]

	double laserOnDelay;                         // ���⿪����ʱʱ�䣬��λ��us
	double laserOffDelay;                        // ����ع���ʱʱ�䣬��λ��us
}TLaserPro;

typedef struct
{
	short powerType;                             // ������������������ź����ͣ�0��ռ�ձȣ�1��Ƶ�ʣ�2������3��ģ������4������
	short group;                                 // �������������group��
	short source;                                // ������������ϳ��ٶ�Դ��0���滮���ϳ��ٶȣ�1���������ϳ��ٶ�
	short coordSystem;                           // ������������ϳ��ٶȵ�����ϵ
	double ratio;                                // ���������������ϵ��
	double minPower;                             // ������������������С����ֵ
	double maxPower;                             // �����������������������ֵ
}TLaserFollowPrmPro;

typedef struct
{
	short powerType;                             // ������������������ź����ͣ�0��ռ�ձȣ�1��Ƶ�ʣ�2������3��ģ������4������
	short group;                                 // �������������group��
	short source;                                // ������������ϳ��ٶ�Դ��0���滮���ϳ��ٶȣ�1���������ϳ��ٶ�
	short coordSystem;                           // ������������ϳ��ٶȵ�����ϵ
	short tableId;                               // �������������ı�ţ�ȡֵ��Χ��[1,2]
	short pad[3];
	double minPower;                             // ������������������С����ֵ
	double maxPower;                             // �����������������������ֵ
}TLaserFollowTablePrmPro;

typedef struct
{
	short group;                                 // �������������group��
	short source;                                // ������������ϳ��ٶ�Դ��0���滮���ϳ��ٶȣ�1���������ϳ��ٶ�
	short coordSystem;                           // ������������ϳ��ٶȵ�����ϵ
	short dutyTableId;                           // ������������ռ�ձȱ�ı�ţ�ȡֵ��Χ��[1,2]
	short frequencyTableId;                      // ������������Ƶ�ʱ�ı�ţ�ȡֵ��Χ��[1,2]
	short pad[3];
	double minDuty;                              // ������������ռ�ձ���С����ֵ��ȡֵ��Χ��[0,100]����λ��%
	double maxDuty;                              // ������������ռ�ձ��������ֵ��ȡֵ��Χ��[0,100]����λ��%
	double minFrequency;                         // ������������Ƶ����С����ֵ��ȡֵ��Χ��[0,1562.5]����λ��kHz
	double maxFrequency;                         // ������������Ƶ���������ֵ��ȡֵ��Χ��[0,1562.5]����λ��kHz
}TLaserFollowDuoTablePrmPro;

typedef struct
{
	short enable;                                // ʹ��
	short mode;                                  // ������������ģʽ
	short errorCode;                             // ���������������ܵĴ�����Ϣ����Ҫ��ʶ����ĵط�
	short returnValue;                           // ���������������ܳ���ط��ķ���ֵ

	double power;                                // ��ǰ����ʵ���������ֵ
	double powerAnother;                         // ͬʱ������������ʱ����һ������ֵ

	TLaserFollowPrmPro ratioPrm;                 // ��mode=LASER_FOLLOW_MODE_RATIOʱ��Ӧ�Ĳ���
	TLaserFollowTablePrmPro tablePrm;            // ��mode=LASER_FOLLOW_MODE_TABLEʱ��Ӧ�Ĳ���
	TLaserFollowDuoTablePrmPro duoTablePrm;      // ��mode=LASER_FOLLOW_MODE_DUO_TABLEʱ��Ӧ�Ĳ���
}TLaserFollowPro;

GT_API GTN_SetLaserEnablePro(short core,short laserChannel,short enable,short mode=0,TListInfo *pListInfo=NULL);
GT_API GTN_SetLaserDelayPro(short core,short laserChannel,double laserOnDelay,double laserOffDelay,TListInfo *pListInfo=NULL);
GT_API GTN_SetLaserPwmPrmPro(short core,short laserChannel,TLaserPwmPrmPro *pPrm,TListInfo *pListInfo=NULL);
GT_API GTN_SetLaserPwmDutyPro(short core,short laserChannel,double duty,TListInfo *pListInfo=NULL);
GT_API GTN_SetLaserPwmFrequencyPro(short core,short laserChannel,double frequency,TListInfo *pListInfo=NULL);
GT_API GTN_SetLaserPwmPulseWidthPro(short core,short laserChannel,double pulseWidth,TListInfo *pListInfo=NULL);
GT_API GTN_SetLaserVoltagePrmPro(short core,short laserChannel,double minVoltage,double maxVoltage,TListInfo *pListInfo=NULL);
GT_API GTN_SetLaserVoltagePro(short core,short laserChannel,double voltage,TListInfo *pListInfo=NULL);
GT_API GTN_SetLaserParallelPrmPro(short core,short laserChannel,double minParallel,double maxParallel,TListInfo *pListInfo=NULL);
GT_API GTN_SetLaserParallelPro(short core,short laserChannel,double parallel,TListInfo *pListInfo=NULL);
GT_API GTN_SetLaserIoPro(short core,short laserChannel,short doType,short doValue,TListInfo *pListInfo=NULL);
GT_API GTN_GetLaserPowerPro(short core,short laserChannel,TLaserPowerPro *pLaserPowerPro);
GT_API GTN_GetLaserPro(short core,short laserChannel,TLaserPro *pLaserPro);
GT_API GTN_SetLaserFollowEnablePro(short core,short laserChannel,short enable,TListInfo *pListInfo=NULL);
GT_API GTN_SetLaserFollowPrmPro(short core,short laserChannel,TLaserFollowPrmPro *pPrm,TListInfo *pListInfo=NULL);
GT_API GTN_SetLaserFollowTablePrmPro(short core,short laserChannel,TLaserFollowTablePrmPro *pPrm,TListInfo *pListInfo=NULL);
GT_API GTN_SetLaserFollowDuoTablePrmPro(short core,short laserChannel,TLaserFollowDuoTablePrmPro *pPrm,TListInfo *pListInfo=NULL);
GT_API GTN_ClearLaserFollowTablePro(short core,short laserChannel,short tableId);
GT_API GTN_SetLaserFollowTablePro(short core,short laserChannel,short tableId,long count,double *pSynchVel,double *pPower);
GT_API GTN_GetLaserFollowTablePro(short core,short laserChannel,short tableId,long count,double *pSynchVel,double *pPower,long *pReadCount);
GT_API GTN_GetLaserFollowPro(short core,short laserChannel,TLaserFollowPro *pLaserFollowPro);

typedef struct  
{
	double kp;
	double ki;
	double kd;
	double kvff;
	double kaff;
	long   integralLimit;
	long   derivativeLimit;
	short  limit;
	short  reserve[3];
}TPidAlign;

typedef struct  
{
	short mode;
	short master;
	short slave;
	short reserve[3];
	long syncErrorLimit;
	TPidAlign gantryMasterPid;
	TPidAlign gantrySlavePid;
	TPidAlign masterPid;
	TPidAlign slavePid;
}TGantryPrmPro;

GT_API GTN_SetGantryPrmPro(short core,short group,TGantryPrmPro *pGantryPrmPro);

//---------------------------------------------------------
// KeSai
//---------------------------------------------------------
typedef struct
{
	unsigned short axis_id;
	unsigned short axis_mode;   // fixed to 1 for Gear
	unsigned short axis_ctrl;   // 0: IDLE; 1: stop; 2: fast_stop; 3: run 
	unsigned short mode;        // 0 : IDLE�� 1���ҿ���run����2������ 3��
	unsigned short reserve;     // must be 0.
	unsigned short reserve2;    // must be 0.
	long modify_delta;
	long ratio_a;      // ����Ϊ��ֵ
	long ratio_b;      // ����Ϊ��ֵ
}TStGearParam;

typedef struct
{
	unsigned short axis_id;
	unsigned short axis_mode;   // fixed to 2 for Trap
	unsigned short axis_ctrl;   // 0: IDLE; 1: stop; 2: fast_stop; 3: run;  
	unsigned short reserve;     // must be 0.
	long long target_pos;
	unsigned long max_vel;
	unsigned short reserve2[2]; // must be 0.
}TStTrapParam;

typedef struct
{
	unsigned short axis_id;
	unsigned short axis_mode;   // fixed to 3 for Jog
	unsigned short axis_ctrl;   // 0: IDLE; 1: stop; 2: fast_stop; 3: run;  
	unsigned short reserve;     // must be 0.

	long target_vel;
	unsigned long max_acc; 
	unsigned long reserve1; 
	unsigned short reserve2[2]; // must be 0.
}TStJogParam;

typedef struct
{
	unsigned short axis_id;
	unsigned short axis_mode;   // fixed to 8 for grantry trap
	unsigned short axis_ctrl;   // 0: IDLE; 1: stop; 2: fast_stop; 3: run;  
	unsigned short reserve;     // must be 0.

	long long target_pos;
	unsigned long max_vel;

	long main_axis_shift;
	long second_axis_shift;
	unsigned short reserve2[2];  // must be 0.
}TStGantrayTrapParam;

typedef struct
{
	unsigned short axis_id;
	unsigned short axis_mode;   // fixed to 16 for driver vel
	unsigned short axis_ctrl;   // 0: IDLE; 1: stop; 2: fast_stop; 3: run ;  
	unsigned short reserve;     // must be 0.

	long target_vel;
	unsigned short reserve3[2]; // must be 0.
	long long reserve2;
}TStDriverVelParam;

typedef struct
{
	unsigned short axis_id;
	unsigned short axis_mode;   // fixed to 17 for driver acc
	unsigned short axis_ctrl;   // 0: IDLE; 1: stop; 2: fast_stop; 3: run ;  
	unsigned short reserve;     // must be 0.

	long target_acc;
	unsigned short reserve3[2]; // must be 0.
	long long reserve2;
}TStDriverCurParam;

typedef struct
{
	short profileMode;
	unsigned short reserve2[3]; //must be 0.
	TStTrapParam trapPrm;
	TStJogParam jogPrm;
	TStGearParam gearPrm;
	TStGantrayTrapParam gantrayTrapPrm;
	TStDriverVelParam driverVelPrm;
	TStDriverCurParam driverCurPrm;
}TSetMultiMcFunctionPrm;

typedef struct
{
	unsigned short prmErrorInf;
	short readCommandVarTableIndex;   // ��ָ�������������
	short readCount;                  // Ҫ���ı�����������
	short pad[2];                     // �ֽڶ��룬����
	short realReadCount;              // ʵ�ʶ�����������
	double* pVarValue;                // ��������ֵ
}TMultiMcFunctionReadPrm;

GT_API GTN_StartMcMultiFunction(short core, unsigned short axisCount, unsigned short writeEnable, TSetMultiMcFunctionPrm* pSetPrm, TMultiMcFunctionReadPrm* pGetPrm);
GT_API GTN_LoadReadCommandVarTable(short core, short tableIndex, char* pFile);
GT_API GTN_ReadCommandVarTable(short core, short tableIndex, double* pVarValue, short count, short* pRealCount);

//---------------------------------------------------------
// Axis Simulation
//---------------------------------------------------------

#define AXISSIMULATION_RESERVE1_SUBMODE           (0)

typedef struct
{
	short enable;
	short reserve1[3];
	double reserve2[4];
} TAxisSimulationParameter;

GT_API GTN_SetAxisSimulationParameter(short core,short profile,TAxisSimulationParameter *pPrm,short count);
GT_API GTN_GetAxisSimulationParameter(short core,short profile,TAxisSimulationParameter *pPrm,short count);
GT_API GTN_GetAxisSimulationBeginPos(short core,short profile,double *pBeginPos,short count);

//����д��Flash����
GT_API GTN_ProgramCardNumToFlash(short core,short coreNum);
GT_API GTN_ReadCardNumFromFlash(short core,short *pCardNum);

//�Ȼ�����������
typedef struct
{
	short varId;
	short stationId;
	short varType;
	short varIndex;
}StSamplingVar;
GT_API GTN_RN_SamplingInit(short cardIndex,short stationPhyId);
GT_API GTN_RN_SamplingAddVar(short cardIndex, short stationPhyId, StSamplingVar stVar);
GT_API GTN_RN_SamplingReadData(short cardIndex,short stationPhyId,short varIdndex,double* pBuffer,long bufSize,long* pReadCount);
GT_API GTN_RN_SamplingClear(short cardIndex, short stationPhyId, short mode);
GT_API GTN_RN_SamplingPrintData(short cardIndex, short stationPhyId, const char* pFileName, long startIndex, unsigned long printCount);
GT_API GTN_RN_SamplingGetInfo(short cardIndex, short stationPhyId, short infoType, unsigned long *pInfo);
GT_API GTN_RN_HighSpeedSamplingGetAllData(short cardIndex,short stationPhyId,unsigned short *pData,unsigned long dataCount,unsigned long *pResDataCount);
GT_API GTN_RN_HighSpeedSamplingOffAll(short cardIndex,short stationPhyId);
GT_API GTN_RN_HighSpeedSamplingOnAll(short cardIndex,short stationPhyId);


