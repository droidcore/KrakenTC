/*
<<<<<<< HEAD
 * interface to control touch boost (= input boost) on OnePlus Two - V2
 *
 * Author: andip71, 20.01.2016
=======
 * interface to control touch boost (= input boost) on OnePlus One bacon
 *
 * Author: andip71, 22.09.2014
>>>>>>> c127efa... cpu-boost: Implement touch boost configuration driver
 *
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/init.h>
#include <linux/device.h>
#include <linux/miscdevice.h>
#include <linux/stat.h>


<<<<<<< HEAD
#define TOUCHBOOST_DURATION_MIN		0
#define TOUCHBOOST_DURATION_MAX		10000


=======
>>>>>>> c127efa... cpu-boost: Implement touch boost configuration driver
/*****************************************/
// Global external variables
/*****************************************/

<<<<<<< HEAD
extern unsigned int touchboost_status_1;
extern unsigned int touchboost_freq_1;
extern unsigned int touchboost_status_2;
extern unsigned int touchboost_freq_2;
extern unsigned int touchboost_ms;

void set_touchboost_parameters(void);
void get_touchboost_parameters(void);

=======
extern unsigned int input_boost_status;
extern unsigned int input_boost_freq;

void set_touchboost_frequency(void);
>>>>>>> c127efa... cpu-boost: Implement touch boost configuration driver

/*****************************************/
// sysfs interface functions
/*****************************************/

<<<<<<< HEAD
static ssize_t touchboost_switch_show_1(struct device *dev, struct device_attribute *attr, char *buf)
{
	get_touchboost_parameters();
	return sprintf(buf, "Touchboost status L: %d", touchboost_status_1);
}


static ssize_t touchboost_switch_store_1(struct device *dev, struct device_attribute *attr,
					const char *buf, size_t count)
{
	unsigned int ret = -EINVAL;
	unsigned int val = 0;

	// read value from input buffer
	ret = sscanf(buf, "%d", &val);

	if (ret != 1)
		return -EINVAL;

	// check if new status is valid
	if ((val != 0) && (val != 1))
	{
		pr_err("Touchboost switch: invalid touchboost L status.\n");
		return -EINVAL;
	}

	touchboost_status_1 = val;
	set_touchboost_parameters();
	return count;

}

static ssize_t touchboost_switch_show_2(struct device *dev, struct device_attribute *attr, char *buf)
{
	get_touchboost_parameters();
	return sprintf(buf, "Touchboost status B: %d", touchboost_status_2);
}


static ssize_t touchboost_switch_store_2(struct device *dev, struct device_attribute *attr,
=======
static ssize_t touchboost_switch_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	// return value of current touchboost status
	return sprintf(buf, "Touchboost status: %d", input_boost_status);
}


static ssize_t touchboost_switch_store(struct device *dev, struct device_attribute *attr,
>>>>>>> c127efa... cpu-boost: Implement touch boost configuration driver
					const char *buf, size_t count)
{
	unsigned int ret = -EINVAL;
	unsigned int val = 0;

	// read value from input buffer
	ret = sscanf(buf, "%d", &val);

	if (ret != 1)
		return -EINVAL;

<<<<<<< HEAD
	// check if new status is valid
	if ((val != 0) && (val != 1))
	{
		pr_err("Touchboost switch: invalid touchboost B status.\n");
		return -EINVAL;
	}

	touchboost_status_2 = val;
	set_touchboost_parameters();
	return count;
}

static ssize_t touchboost_freq_show_1(struct device *dev, struct device_attribute *attr, char *buf)
{
	get_touchboost_parameters();
	return sprintf(buf, "%d - Touchboost frequency\n", touchboost_freq_1);
}

static ssize_t touchboost_freq_store_1(struct device *dev, struct device_attribute *attr,
					const char *buf, size_t count)
{
	unsigned int ret = -EINVAL;
	unsigned int input = 0;

	// read value from input buffer
	ret = sscanf(buf, "%d", &input);

	if (ret != 1)
		return -EINVAL;

	if (input == 0) 
		return -EINVAL;

	touchboost_freq_1 = input;
	set_touchboost_parameters();
	return count;
}

static ssize_t touchboost_freq_show_2(struct device *dev, struct device_attribute *attr, char *buf)
{
	get_touchboost_parameters();
	return sprintf(buf, "%d - Touchboost frequency\n", touchboost_freq_2);
}


static ssize_t touchboost_freq_store_2(struct device *dev, struct device_attribute *attr,
=======
	// check if new status is valid and store in external variable
	if ((val == 0) || (val == 1))
		input_boost_status = val;
	else
		pr_err("Touchboost switch : invalid touchboost status.\n");

	return count;
}

static ssize_t touchboost_freq_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	// return value of current touchboost frequency
	return sprintf(buf, "%d - Touchboost frequency\n", input_boost_freq);
}


static ssize_t touchboost_freq_store(struct device *dev, struct device_attribute *attr,
>>>>>>> c127efa... cpu-boost: Implement touch boost configuration driver
					const char *buf, size_t count)
{
	unsigned int ret = -EINVAL;
	unsigned int input = 0;

	// read value from input buffer
	ret = sscanf(buf, "%d", &input);

	if (ret != 1)
		return -EINVAL;

	if (input == 0) 
<<<<<<< HEAD
		return -EINVAL;

	touchboost_freq_2 = input;
	set_touchboost_parameters();
	return count;
}


static ssize_t touchboost_ms_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	get_touchboost_parameters();
	return sprintf(buf, "%d - Touchboost impulse length (ms)\n", touchboost_ms);
}


static ssize_t touchboost_ms_store(struct device *dev, struct device_attribute *attr,
					const char *buf, size_t count)
{
	unsigned int ret = -EINVAL;
	unsigned int input = 0;

	// read value from input buffer
	ret = sscanf(buf, "%d", &input);

	if (ret != 1)
		return -EINVAL;

	// check if value is valid
	if ((input < TOUCHBOOST_DURATION_MIN) || (input > TOUCHBOOST_DURATION_MAX))
	{
		pr_err("Touchboost switch: invalid duration value requested");
		return -EINVAL;
	}

	touchboost_ms = input;
	set_touchboost_parameters();
	return count;
=======
	{
		pr_err("Touchboost switch : frequency not allowed");
		return -EINVAL;
	} 
	else 
	{
		input_boost_freq = input;
		set_touchboost_frequency();
		pr_debug("Touchboost switch : frequency for touch boost set");
	}

	return -EINVAL;
>>>>>>> c127efa... cpu-boost: Implement touch boost configuration driver
}


/*****************************************/
// Initialize touchboost switch sysfs
/*****************************************/

// define objects
<<<<<<< HEAD
static DEVICE_ATTR(touchboost_switch, S_IRUGO | S_IWUGO, touchboost_switch_show_1, touchboost_switch_store_1);
static DEVICE_ATTR(touchboost_freq  , S_IRUGO | S_IWUGO, touchboost_freq_show_1 ,touchboost_freq_store_1);
static DEVICE_ATTR(touchboost_switch_2, S_IRUGO | S_IWUGO, touchboost_switch_show_2, touchboost_switch_store_2);
static DEVICE_ATTR(touchboost_freq_2  , S_IRUGO | S_IWUGO, touchboost_freq_show_2 , touchboost_freq_store_2);
static DEVICE_ATTR(touchboost_ms  , S_IRUGO | S_IWUGO, touchboost_ms_show , touchboost_ms_store);
=======
static DEVICE_ATTR(touchboost_switch, S_IRUGO | S_IWUGO, touchboost_switch_show, touchboost_switch_store);
static DEVICE_ATTR(touchboost_freq  , S_IRUGO | S_IWUGO, touchboost_freq_show  , touchboost_freq_store  );
>>>>>>> c127efa... cpu-boost: Implement touch boost configuration driver

// define attributes
static struct attribute *touchboost_switch_attributes[] = {
	&dev_attr_touchboost_switch.attr,
	&dev_attr_touchboost_freq.attr,
<<<<<<< HEAD
	&dev_attr_touchboost_switch_2.attr,
	&dev_attr_touchboost_freq_2.attr,
	&dev_attr_touchboost_ms.attr,
=======
>>>>>>> c127efa... cpu-boost: Implement touch boost configuration driver
	NULL
};

// define attribute group
static struct attribute_group touchboost_switch_control_group = {
	.attrs = touchboost_switch_attributes,
};

// define control device
static struct miscdevice touchboost_switch_control_device = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "touchboost_switch",
};


/*****************************************/
// Driver init and exit functions
/*****************************************/

static int touchboost_switch_init(void)
{
	// register touchboost switch device
	misc_register(&touchboost_switch_control_device);
	if (sysfs_create_group(&touchboost_switch_control_device.this_device->kobj,
				&touchboost_switch_control_group) < 0) {
<<<<<<< HEAD
		pr_info("Touchboost switch : failed to create touchboost switch sys fs object.\n");
=======
		pr_err("Touchboost switch : failed to create touchboost switch sys fs object.\n");
>>>>>>> c127efa... cpu-boost: Implement touch boost configuration driver
		return 0;
	}

	pr_info("Touchboost switch : device initialized\n");

	return 0;
}


static void touchboost_switch_exit(void)
{
	// remove touchboost switch device
	sysfs_remove_group(&touchboost_switch_control_device.this_device->kobj,
                           &touchboost_switch_control_group);

	pr_info("Touchboost switch : device stopped\n");
}


/* define driver entry points */

module_init(touchboost_switch_init);
module_exit(touchboost_switch_exit);
