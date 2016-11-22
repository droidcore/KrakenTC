#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/hrtimer.h>
#include <linux/proc_fs.h>
#include <linux/interrupt.h>
#include <linux/regulator/consumer.h>
#include <linux/firmware.h>

#include <linux/pinctrl/consumer.h>
#include <linux/pinctrl/pinctrl.h>
#include <linux/pinctrl/machine.h>

#include <linux/kthread.h>
#include <linux/random.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/sched/rt.h>
#include <linux/task_work.h>

#include <linux/rtc.h>
#include <linux/syscalls.h>
#include <linux/timer.h>
#include <linux/time.h>

#ifdef CONFIG_BOEFFLA_TOUCH_KEY_CONTROL
#include <linux/boeffla_touchkey_control.h>
#endif

#ifdef CONFIG_FB
#include <linux/fb.h>
#include <linux/notifier.h>
#endif

#include <linux/input/mt.h>

#include "synaptics_redremote.h"
#include <linux/boot_mode.h>
#include <linux/project_info.h>
#include "synaptics_baseline.h"
/*------------------------------------------------Global Define--------------------------------------------*/

#define TP_UNKNOWN 0
#define TP_G2Y 1
#define TP_TPK 2
#define TP_TRULY 3
#define TP_OFILM 4
#define TP_JDI_TPK 6
