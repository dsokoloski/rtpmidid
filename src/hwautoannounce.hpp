/**
 * Real Time Protocol Music Instrument Digital Interface Daemon
 * Copyright (C) 2019-2024 David Moreno Montero <dmoreno@coralbits.com>
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

#include "aseq.hpp"
#include "midirouter.hpp"
#include <memory>
#include <rtpmidid/signal.hpp>
#include <string>

namespace rtpmididns {
class HwAutoAnnounce {
public:
  std::shared_ptr<midirouter_t> router;
  std::shared_ptr<aseq_t> aseq;
  std::vector<aseq_t::connection_t> connections;

  rtpmidid::connection_t<const std::string &, aseq_t::client_type_e,
                         const aseq_t::port_t &>
      added_client_announcement_connection;
  rtpmidid::connection_t<const aseq_t::port_t &>
      removed_port_announcement_connection;

  HwAutoAnnounce(std::shared_ptr<aseq_t> aseq,
                 std::shared_ptr<midirouter_t> router);
  ~HwAutoAnnounce();

  void added_port_announcement(const std::string &name,
                               aseq_t::client_type_e type,
                               const aseq_t::port_t &port);
  void removed_port_announcement(const aseq_t::port_t &port);
};

} // namespace rtpmididns