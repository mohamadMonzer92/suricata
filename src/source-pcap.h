/* Copyright (C) 2007-2010 Open Information Security Foundation
 *
 * You can copy, redistribute or modify this Program under the terms of
 * the GNU General Public License version 2 as published by the Free
 * Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * version 2 along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

/**
 * \file
 *
 * \author Victor Julien <victor@inliniac.net>
 */

#ifndef __SOURCE_PCAP_H__
#define __SOURCE_PCAP_H__

void TmModuleReceivePcapRegister (void);
void TmModuleDecodePcapRegister (void);
void PcapTranslateIPToDevice(char *pcap_dev, size_t len);

int PcapLiveRegisterDevice(char *);
int PcapLiveGetDeviceCount(void);
char *PcapLiveGetDevice(int);

/* XXX replace with user configurable options */
#define LIBPCAP_SNAPLEN     1518
#define LIBPCAP_COPYWAIT    500
#define LIBPCAP_PROMISC     1

/* per packet Pcap vars */
typedef struct PcapPacketVars_
{
} PcapPacketVars;

#define PCAP_IFACE_NAME_LENGTH 48

typedef struct PcapIfaceConfig_
{
    char iface[PCAP_IFACE_NAME_LENGTH];
    /* socket buffer size */
    int buffer_size;
    /* BPF filter */
    char *bpf_filter;
    SC_ATOMIC_DECLARE(unsigned int, ref);
    void (*DerefFunc)(void *);
} PcapIfaceConfig;



#endif /* __SOURCE_PCAP_H__ */

