/*
 * dni_netfilter_sysctl.c: DNI netfilter sysctl interface to net subsystem.
 *
 * Copyright (C) 2010 Delta Networks Inc.
 *
 */
#ifdef CONFIG_SYSCTL
#include <linux/sysctl.h>
#include <net/netfilter/nf_conntrack.h>

/* For storing present lan interface ipv4 address, Inclusive: host order */
u32 lan_ipv4_address = 0;
/* For storing present lan interface ipv4 mask, Inclusive: host order */
u32 lan_ipv4_mask = 0;
/* For storing present wan interface ipv4 address, Inclusive: host order */
u32 wan_ipv4_address = 0;
/* For storing second wan interface ipv4 address, Inclusive: host order */
u32 second_wan_ipv4_address = 0;
/* For enable or disable NAT Session Management feature */
extern int sysctl_enable_nat_management;

ctl_table dni_table[] = {
	{
		.ctl_name       = CTL_UNNUMBERED,
		.procname       = "lan_ipv4_address",
		.data           = &lan_ipv4_address,
		.maxlen         = sizeof(int),
		.mode           = 0644,
		.proc_handler   = proc_dointvec,
		.strategy       = sysctl_intvec,
	},
	{
		.ctl_name       = CTL_UNNUMBERED,
		.procname       = "lan_ipv4_mask",
		.data           = &lan_ipv4_mask,
		.maxlen         = sizeof(int),
		.mode           = 0644,
		.proc_handler   = proc_dointvec,
		.strategy       = sysctl_intvec,
	},
	{
		.ctl_name	= CTL_UNNUMBERED,
		.procname	= "wan_ipv4_address",
		.data		= &wan_ipv4_address,
		.maxlen		= sizeof(int),
		.mode		= 0644,
		.proc_handler	= proc_dointvec,
		.strategy	= sysctl_intvec,
	},
	{
		.ctl_name	= CTL_UNNUMBERED,
		.procname	= "enable_nat_management",
		.data		= &sysctl_enable_nat_management,
		.maxlen		= sizeof(int),
		.mode		= 0644,
		.proc_handler	= proc_dointvec,
		.strategy	= sysctl_intvec,
	},
	{
		.ctl_name	= CTL_UNNUMBERED,
		.procname	= "second_wan_ipv4_address",
		.data		= &second_wan_ipv4_address,
		.maxlen		= sizeof(int),
		.mode		= 0644,
		.proc_handler	= proc_dointvec,
		.strategy	= sysctl_intvec,
	},
	{0}
};

ctl_table dni_netfilter_sysctl_table[2] = {
	{
		.ctl_name	= CTL_UNNUMBERED,
		.procname	= "dni_netfilter",
		.mode		= 0555,
		.child		= dni_table
	},
	{0}
};
EXPORT_SYMBOL(dni_netfilter_sysctl_table);
#endif
