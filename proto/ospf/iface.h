/*
 *      BIRD -- OSPF
 *
 *      (c) 1999 Ondrej Filip <feela@network.cz>
 *
 *      Can be freely distributed and used under the terms of the GNU GPL.
 *
 */

#ifndef _BIRD_OSPF_IFACE_H_
#define _BIRD_OSPF_IFACE_H_

void iface_chstate(struct ospf_iface *ifa, u8 state);
void downint(struct ospf_iface *ifa);
void ospf_int_sm(struct ospf_iface *ifa, int event);
sock *ospf_open_mc_socket(struct ospf_iface *ifa);
sock *ospf_open_ip_socket(struct ospf_iface *ifa);
u8 is_good_iface(struct proto *p, struct iface *iface);
u8 ospf_iface_clasify(struct iface *ifa);
void ospf_add_timers(struct ospf_iface *ifa, pool *pool);
void ospf_iface_default(struct ospf_iface *ifa);
struct ospf_iface *find_iface(struct proto_ospf *p, struct iface *what);
void ospf_if_notify(struct proto *p, unsigned flags, struct iface *iface);

#endif /* _BIRD_OSPF_IFACE_H_ */