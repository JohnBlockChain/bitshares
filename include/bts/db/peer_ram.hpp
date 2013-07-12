#pragma once
#include <bts/db/peer.hpp>

namespace bts { namespace db {
  
   namespace detail { class peer_ram_impl; }

   /**
    *  @brief manages the peer database in memory, nothing
    *  persists after relaunch.
    */
   class peer_ram : public peer 
   {
       public:
         peer_ram();
         virtual  ~peer_ram();
         virtual void          store( const record& r );
         virtual record        fetch( const fc::ip::endpoint& ep );
         virtual void          remove( const fc::ip::endpoint& ep );
         virtual uint32_t      inactive_count()const;

         virtual void          set_active( const fc::ip::endpoint& ep, bool a = true );

         virtual record        get_random_inactive()const;
       private:
         std::unique_ptr<detail::peer_ram_impl> my;
   };

   typedef std::shared_ptr<peer_ram> peer_ram_ptr;

} }
