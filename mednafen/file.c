/* Mednafen - Multi-system Emulator
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include <streams/file_stream.h>

#include "file.h"

struct MDFNFILE *file_open_mem(const uint8_t *data, int64_t size)
{
   struct MDFNFILE *file = (struct MDFNFILE*)calloc(1, sizeof(*file));

   if (!file)
      return NULL;
   
   if (!data || !size)
      return NULL;

   file->data     = (uint8_t*)data;
   file->size     = size;
   file->ext      = 0;
   file->location = 0;

   return file;
}

struct MDFNFILE *file_open(const char *path)
{
   int64_t size          = 0;
   const char        *ld = NULL;
   struct MDFNFILE *file = (struct MDFNFILE*)calloc(1, sizeof(*file));

   if (!file)
      return NULL;

   if (!filestream_read_file(path, (void**)&file->data, &size))
      goto error;

   ld         = (const char*)strrchr(path, '.');
   file->size = size;
   file->ext  = strdup(ld ? ld + 1 : "");

   return file;

error:
   if (file)
      free(file);
   return NULL;
}

int file_close(struct MDFNFILE *file)
{
   if (!file)
      return 0;

   if (file->ext)
      free(file->ext);
   file->ext = NULL;

   if (file->data)
      free(file->data);
   file->data = NULL;

   free(file);

   return 1;
}

uint64_t file_read(struct MDFNFILE *file, void *ptr,
      size_t element_size, size_t nmemb)
{
   uint32_t total = element_size * nmemb;

   if (file->location >= file->size)
      return 0;

   if ((file->location + total) > file->size)
   {
      int64_t ak = file->size - file->location;

      memcpy((uint8_t*)ptr, file->data + file->location, ak);

      file->location = file->size;

      return(ak / element_size);
   }

   memcpy((uint8_t*)ptr, file->data + file->location, total);

   file->location += total;

   return nmemb;
}

int file_seek(struct MDFNFILE *file, int64_t offset, int whence)
{
   switch(whence)
   {
      case SEEK_SET:
         if (offset >= file->size)
            return -1;

         file->location = offset;
         break;
      case SEEK_CUR:
         if ((offset + file->location) > file->size)
            return -1;

         file->location += offset;
         break;
   }    

   return 0;
}
