#ifndef __define__
#define __define__

#define RETURN_SUCCESS 1
#define RETURN_FAILED 0
typedef int return_t;

//#define __debug__	//�f�o�b�O�̎���`
#define __debug_calling__	//�Ăяo���֘A�̃f�o�b�O���ɒ�`
#define __debug_searching__	//�����֘A�̃f�o�b�O���ɒ�`
//#define __debug_pointing__	//��ʍ��W�擾���[�h���ɒ�`
//#define __auto_input__

#define setting_path "../setting.ini"	//�ݒ�t�@�C���̃p�X

#define macro_continue 10	//�}�N���̏z��`�h�~


#define RETURN_SUCCESS	1
#define RETURN_FAILED	0

#define QUEUE_EXIT 1
#define QUEUE_CONTINUE 2

#define debug_message_line "\t------------------------------------------------------------"
#define debug_message_line_fatal "\t************************************************************"

#ifdef __debug__

#define debug_message_called(name) cui << debug_message_line << "\n\t\t" << (name) << " called.\n" << debug_message_line << "\n\n"
#define debug_message_returned(name) cui << debug_message_line << "\n\t\t" << "returned to " << (name) << "\n" << debug_message_line << "\n\n"

#else
#define debug_message_called(name) NULL
#define debug_message_returned(name) NULL

#endif

#endif
