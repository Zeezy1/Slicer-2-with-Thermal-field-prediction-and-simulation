#ifndef GCODE_TORMACH_SAVER_H
#define GCODE_TORMACH_SAVER_H

// Qt
#include <QThread>

#include "gcode/gcode_meta.h"

namespace ORNL
{
    /*!
     * \class GCodeTormachSaver
     * \brief Threaded class that provides additional gcode processing.  Currently for Tormach
     */
    class GCodeTormachSaver : public QThread {
        Q_OBJECT
        public:
            //! \brief Constructor
            //! \param tempLocation: location of gcode file
            //! \param path: path to output
            //! \param filename: filename to output
            //! \param text: current gcode
            //! \param meta: meta used to generate gcode
            GCodeTormachSaver(QString tempLocation, QString path, QString filename, QString text, GcodeMeta meta);

            //! \brief Function that is run when start is called on this thread.
            void run() override;

        private:
            //! \brief Temporary file location, output path, output filename, and text to output
            QString m_temp_location, m_path, m_filename, m_text;

            //! \brief Meta info determined from file
            GcodeMeta m_selected_meta;

    };  // class GCodeTormachSaver
}  // namespace ORNL
#endif // GCODE_TORMACH_SAVER_H
