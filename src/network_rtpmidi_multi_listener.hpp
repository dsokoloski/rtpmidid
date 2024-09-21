/**
 * Real Time Protocol Music Instrument Digital Interface Daemon
 * Copyright (C) 2019-2023 David Moreno Montero <dmoreno@coralbits.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once
#include "midipeer.hpp"
#include "rtpmidid/rtpserver.hpp"
#include <memory>
#include <string>

namespace rtpmididns {
class aseq_t;
class midirouter_t;

/**
 * @short A rtpmidi server that creates local listen ALSA ports
 *
 * This midipeer does not actually send or receive data, but creates
 * a local ALSA peer and a rtpmidi peer and connects them.
 */
class network_rtpmidi_multi_listener_t : public midipeer_t {
public:
  std::shared_ptr<aseq_t> aseq;
  rtpmidid::rtpserver_t server;
  rtpmidid::connection_t<const rtpmidid::io_bytes_reader &> midi_connection;
  rtpmidid::connection_t<std::shared_ptr<rtpmidid::rtppeer_t>>
      connected_connection;

  network_rtpmidi_multi_listener_t(const std::string &name,
                                   const std::string &port,
                                   std::shared_ptr<aseq_t> aseq);
  void send_midi(midipeer_id_t from, const mididata_t &) override;
  json_t status() override;
  const char *get_type() const override {
    return "network_rtpmidi_multi_listener_t";
  }
};
} // namespace rtpmididns
